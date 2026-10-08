// ============================================================
// DEPTHWIZARD
// COLLAPSIBLE SIDEBAR WORKSTATION SECTIONS
// ============================================================

const STORAGE_KEY = 'depthwizard.sidebar.sections.v3';

const DEFAULT_COLLAPSED = new Set([
    'Data · Mission Overview',
    'Validate · Reference Comparison',
    'Explore · Visual Controls',
    'Advanced · Hydrology',
    'Output · 360° View',
    'Output · Exports & Evidence'
]);

function loadState() {
    try {
        const raw = localStorage.getItem(STORAGE_KEY);
        return raw ? JSON.parse(raw) : {};
    } catch {
        return {};
    }
}

function saveState(state) {
    try {
        localStorage.setItem(STORAGE_KEY, JSON.stringify(state));
    } catch {
        // Local storage is optional.
    }
}

function applySectionState(section, collapsed, button) {
    section.classList.toggle('is-collapsed', collapsed);
    button.textContent = collapsed ? '+' : '−';
    button.setAttribute('aria-expanded', String(!collapsed));
    button.setAttribute('aria-label', collapsed ? 'Expand section' : 'Collapse section');
}

export function initSidebarUI() {
    const saved = loadState();
    const savedState = { ...saved };

    document.querySelectorAll('#sidebar .sidebar-section').forEach((section, index) => {
        const header = section.querySelector('.section-header');
        if (!header) return;

        // Avoid duplicate controls during hot reload.
        if (header.querySelector('.section-collapse-btn')) return;

        const title = header.querySelector('.section-title')?.textContent?.trim() || `section-${index}`;
        const isCoreInput = title === 'Load Imagery';
        // Keep the primary upload/generation section always visible and clean.
        if (isCoreInput) {
            return;
        }

        const button = document.createElement('button');
        button.type = 'button';
        button.className = 'section-collapse-btn';
        button.dataset.section = title;
        button.title = 'Collapse section';

        const hasSaved = Object.prototype.hasOwnProperty.call(savedState, title);
        const collapsed = hasSaved ? Boolean(savedState[title]) : DEFAULT_COLLAPSED.has(title);

        header.appendChild(button);
        applySectionState(section, collapsed, button);

        button.addEventListener('click', (event) => {
            event.preventDefault();
            event.stopPropagation();
            const next = !section.classList.contains('is-collapsed');
            applySectionState(section, next, button);
            savedState[title] = next;
            saveState(savedState);
        });
    });
}
