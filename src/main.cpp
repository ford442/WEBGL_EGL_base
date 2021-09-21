#include <string>
#include <emscripten/html5.h>
#include <GLES3/gl3.h>
#include <emscripten.h>
#include <EGL/egl.h>
static EGLint attribute_list[]={
EGL_RED_SIZE,8,
EGL_GREEN_SIZE,8,
EGL_BLUE_SIZE,8,
EGL_ALPHA_SIZE,8,
EGL_DEPTH_SIZE,0,
EGL_STENCIL_SIZE,0,
EGL_BUFFER_SIZE,32,
EGL_CONFORMANT,EGL_OPENGL_ES2_BIT,
EGL_BIND_TO_TEXTURE_RGBA,EGL_TRUE,
EGL_TRANSPARENT_TYPE,EGL_TRANSPARENT_RGB,
EGL_NONE
};
int main(){
EmscriptenWebGLContextAttributes attr;
attr.alpha = 1;
attr.depth = 0;
attr.antialias = 0;
attr.premultipliedAlpha = 0;
attr.preserveDrawingBuffer = 0;
emscripten_webgl_init_context_attributes(&attr);
EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx=emscripten_webgl_create_context("#canvas",&attr);
emscripten_webgl_make_context_current(ctx);
EGLConfig eglconfig=NULL;
EGLint config_size,major,minor;
EGLContext contextegl;
EGLDisplay display=eglGetDisplay(EGL_DEFAULT_DISPLAY);
eglInitialize(display,&major,&minor);
if(eglChooseConfig(display,attribute_list,&eglconfig,1,&config_size)==EGL_TRUE && eglconfig!=NULL){
if(eglBindAPI(EGL_OPENGL_ES_API)!=EGL_TRUE){
}
EGLint anEglCtxAttribs2[]={EGL_CONTEXT_CLIENT_VERSION,3,EGL_NONE,EGL_NONE};
contextegl=eglCreateContext (display,eglconfig,EGL_NO_CONTEXT,anEglCtxAttribs2);
if(contextegl==EGL_NO_CONTEXT){
}else{
EGLSurface surface=eglCreateWindowSurface(display,eglconfig,NULL,NULL);
eglMakeCurrent(display,surface,surface,contextegl);
glClearColor(1.0,0.0,0.0,0.5);
glClear(GL_COLOR_BUFFER_BIT);
}}
return 1;
}
