var MyModule =
{
    canvas: (function() {
    var aCanvas = document.getElementById('canvas');
    aGlCtx = aCanvas.getContext ('webgl2',  { alpha: true, depth: true, antialias: false, preserveDrawingBuffer: true } ); 
    return aCanvas;
  })(),

};

const OccViewerModuleInitialized = createModule(MyModule);
