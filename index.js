// var MyModule ={canvas: (function() {var aCanvas = document.getElementById('canvas');var aGlCtx;return aCanvas;  })(),};
// var MyModule;
// const OccViewerModuleInitialized = createModule(MyModule);

// var Module.canvas=document.getElementById('canvas');
// var canvas=document.getElementById('canvas');
// var Module={canvas:(function(){let acanvas=document.getElementById('canvas');return acanvas;})(),
// };

// var Module={canvas:(function(){canvas=document.getElementById('canvas');return canvas;})()};

var MyModule =
{
    canvas: (function() {
    var aCanvas = document.getElementById('canvas');
    aGlCtx = aCanvas.getContext ('webgl',  { alpha: false, depth: true, antialias: false, preserveDrawingBuffer: true } ); 
    return aCanvas;
  })(),

};

const OccViewerModuleInitialized = createModule(MyModule);



