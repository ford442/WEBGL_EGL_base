var mod={canvas:(function(){var can=document.getElementById('canvas');return can;})(),};
const OccViewerModuleInitialized=createModule(mod);
document.getElementById('btn2').addEventListener('click',function(){
mod.ccall('jsdraw');
});
