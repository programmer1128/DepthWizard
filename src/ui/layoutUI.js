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

function setSidebar(collapsed, persist = true, resetScroll = true) {
    const workspace = document.getElementById('workspace');
    const sidebar = document.getElementById('sidebar');
    const panel = document.getElementById('sidebarPanel');
    const button = document.getElementById('sidebarToggleBtn');
    if (!workspace || !sidebar || !button) return;

    workspace.classList.toggle('sidebar-collapsed', collapsed);
    sidebar.classList.toggle('panel-collapsed', collapsed);

    button.setAttribute('aria-expanded', String(!collapsed));
    button.setAttribute('aria-label', collapsed ? 'Show tool panel' : 'Hide tool panel');
    button.title = collapsed ? 'Show tool panel' : 'Hide tool panel';

    const icon = button.querySelector('.layout-toggle-icon');
    if (icon) icon.textContent = collapsed ? '›' : '‹';

    if (persist) writeBool(SIDEBAR_KEY, collapsed);

    // Reopening always brings the important upload / Generate 3D Terrain area
    // back into view instead of reopening on an arbitrary old scroll offset.
    if (!collapsed && panel && resetScroll) {
        window.requestAnimationFrame(() => {
            panel.scrollTop = 0;
        });
    }
}

export function initLayoutUI() {
    const sidebarButton = document.getElementById('sidebarToggleBtn');

    if (sidebarButton) {
        sidebarButton.addEventListener('click', () => {
            const sidebar = document.getElementById('sidebar');
            const collapsed = Boolean(sidebar?.classList.contains('panel-collapsed'));
            setSidebar(!collapsed);
        });
    }

    setSidebar(readBool(SIDEBAR_KEY, false), false);

    const railButtons = Array.from(document.querySelectorAll('[data-rail-target]'));
    const setRailActive = (targetId) => {
        railButtons.forEach((button) => {
            button.classList.toggle(
                'is-active',
                button.getAttribute('data-rail-target') === targetId
            );
        });
    };

    const scrollPanelTo = (target) => {
        const panel = document.getElementById('sidebarPanel');
        if (!panel || !target) return;

        panel.scrollTo({
            top: Math.max(0, target.offsetTop - 12),
            behavior: 'smooth'
        });
    };

    document.querySelectorAll('[data-rail-target]').forEach((button) => {
        button.addEventListener('click', () => {
            const targetId = button.getAttribute('data-rail-target');
            const target = targetId ? document.getElementById(targetId) : null;
            if (!target) return;

            setSidebar(false, true, false);
            setRailActive(targetId);
            scrollPanelTo(target);
        });
    });

    document.querySelector('[data-rail-action="help"]')?.addEventListener('click', () => {
        document.getElementById('help-panel')?.classList.toggle('show');
    });

    document.addEventListener('keydown', (event) => {
        const target = event.target;
        const typing = target instanceof HTMLInputElement ||
            target instanceof HTMLTextAreaElement ||
            target instanceof HTMLSelectElement ||
            target?.isContentEditable;
        if (typing || event.ctrlKey || event.metaKey || event.altKey) return;

        if (event.key === '[') {
            event.preventDefault();
            const collapsed = Boolean(document.getElementById('sidebar')?.classList.contains('panel-collapsed'));
            setSidebar(!collapsed);
        }
    });
}
