mergeInto(LibraryManager.library, {
  DispatchBrowserEvent: function (eventNamePtr, payloadPtr) {
    var eventName = UTF8ToString(eventNamePtr);
    var payloadStr = UTF8ToString(payloadPtr);
    var payload = null;

    try {
      payload = JSON.parse(payloadStr);
    } catch (e) {
      payload = payloadStr;
    }

    // 1. Dispatch custom DOM event on window
    if (typeof window !== "undefined") {
      var event = new CustomEvent(eventName, { detail: payload });
      window.dispatchEvent(event);

      // 2. Direct hook invocation if consumer set window.onUnityBridgeEvent
      if (typeof window.onUnityBridgeEvent === "function") {
        window.onUnityBridgeEvent(eventName, payload);
      }
    }
  }
});
