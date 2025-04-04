
(function() {
    'use strict';

    function removeShortsEntry() {
        const element = document.querySelector('#endpoint[title="Shorts"]');
        if (element) {
            element.remove();
        }
    }

    removeShortsEntry();

    const observer = new MutationObserver(() => {
        removeShortsEntry();
    });

    observer.observe(document.body, { childList: true, subtree: true });
})();
