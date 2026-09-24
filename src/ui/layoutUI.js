// ============================================================
// DEPTHWIZARD
// WORKSTATION LAYOUT CONTROLS
// Sidebar collapse only. Header remains fixed and always visible.
// ============================================================

const SIDEBAR_KEY = 'depthwizard.layout.sidebarCollapsed.v2';

function readBool(key, fallback = false) {
    try {
        const value = localStorage.getItem(key);
        return value == null ? fallback : value === 'true';
    } catch {
        return fallback;
    }
}

function writeBool(key, value) {
    try {
        localStorage.setItem(key, String(Boolean(value)));
    } catch {
        // Local storage is optional.
    }
}

function setSidebar(collapsed, persist = true) {
    const workspace = document.getElementById('workspace');
    const sidebar = document.getElementById('sidebar');
    const button = document.getElementById('sidebarToggleBtn');
    if (!workspace || !sidebar || !button) return;

    workspace.classList.toggle('sidebar-collapsed', collapsed);
    sidebar.classList.toggle('is-collapsed', collapsed);

    button.setAttribute('aria-expanded', String(!collapsed));
    button.setAttribute('aria-label', collapsed ? 'Expand sidebar' : 'Collapse sidebar');
    button.title = collapsed ? 'Expand sidebar' : 'Collapse sidebar';

    const icon = button.querySelector('.layout-toggle-icon');
    if (icon) icon.textContent = collapsed ? '›' : '‹';

    if (persist) writeBool(SIDEBAR_KEY, collapsed);

    // Reopening always brings the important upload / Generate 3D Map area
    // back into view instead of reopening on an arbitrary old scroll offset.
    if (!collapsed) {
        window.requestAnimationFrame(() => {
            sidebar.scrollTop = 0;
        });
    }
}

export function initLayoutUI() {
    const sidebarButton = document.getElementById('sidebarToggleBtn');

    if (sidebarButton) {
        sidebarButton.addEventListener('click', () => {
            const workspace = document.getElementById('workspace');
            const collapsed = Boolean(workspace?.classList.contains('sidebar-collapsed'));
            setSidebar(!collapsed);
        });
    }

    setSidebar(readBool(SIDEBAR_KEY, false), false);

    document.addEventListener('keydown', (event) => {
        const target = event.target;
        const typing = target instanceof HTMLInputElement ||
            target instanceof HTMLTextAreaElement ||
            target instanceof HTMLSelectElement ||
            target?.isContentEditable;
        if (typing || event.ctrlKey || event.metaKey || event.altKey) return;

        if (event.key === '[') {
            event.preventDefault();
            const collapsed = Boolean(document.getElementById('workspace')?.classList.contains('sidebar-collapsed'));
            setSidebar(!collapsed);
        }
    });
}
