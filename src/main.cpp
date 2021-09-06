#include "func.h"
#include <emscripten/html5.h>
#include <GLES2/gl2.h>
#include <emscripten.h>
#include <EGL/egl.h>

static EGLint attribute_list[] ={
EGL_RED_SIZE,8,
EGL_GREEN_SIZE,8,
EGL_BLUE_SIZE,8,
EGL_ALPHA_SIZE,8,
EGL_DEPTH_SIZE,24,
EGL_STENCIL_SIZE,8,
EGL_NONE
};
void draw(){
EmscriptenWebGLContextAttributes attr;
emscripten_webgl_init_context_attributes(&attr);
EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx=emscripten_webgl_create_context("#canvas",&attr);
emscripten_webgl_make_context_current(ctx);
glClearColor(0.0,1.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
EGLConfig eglconfig=NULL;
EGLint config_size,major,minor;
EGLContext contextegl;
EGLDisplay display=eglGetDisplay(EGL_DEFAULT_DISPLAY);
eglInitialize(display,&major,&minor);
if (eglChooseConfig (display,attribute_list,&eglconfig,1,&config_size) == EGL_TRUE && eglconfig != NULL){
if (eglBindAPI(EGL_OPENGL_ES_API) != EGL_TRUE)printjs("EglBindAPI failed");
EGLint anEglCtxAttribs2[]={ EGL_CONTEXT_CLIENT_VERSION,2,EGL_NONE,EGL_NONE }; // Spécification d'OpenGL ES 2
contextegl=eglCreateContext (display,eglconfig,EGL_NO_CONTEXT,anEglCtxAttribs2);
if (contextegl == EGL_NO_CONTEXT){
printjs("eglCreateContext failed ");
}else{
printjs("eglCreateContext success ! ");
EGLSurface surface=eglCreateWindowSurface(display,eglconfig,NULL,NULL);
eglMakeCurrent(display,surface,surface,contextegl);
glClearColor(0.7,0.0,0.8,0.8);
glClear(GL_COLOR_BUFFER_BIT);
}}}

int main(){
  return 1;
}
