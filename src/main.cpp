#include <math.h>
#include "func.h"
#include <emscripten/html5.h>
#include <GLES2/gl2.h>
#include <emscripten.h>
#include <EGL/egl.h>
#include <GL/glew.h>


static EGLint attribute_list[] ={
EGL_RED_SIZE,8,
EGL_GREEN_SIZE,8,
EGL_BLUE_SIZE,8,
EGL_ALPHA_SIZE,8,
EGL_DEPTH_SIZE,24,
EGL_STENCIL_SIZE,8,
EGL_NONE
};
extern "C" {
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
const int sides = 20;
const double radius = 5; 
glBegin(GL_LINE_LOOP);
for (int a = 0; a < 360; a += 360 / sides){
double heading = a * 3.1415926535897932384626433832795 / 180;
glVertex2d(cos(heading) * radius, sin(heading) * radius);
}
glEnd();
glFlush();
}}}}
int main(){
EM_ASM(
document.getElementById('btn2').addEventListener('click', function(){
Module.ccall('draw');
});
document.getElementById('btn').addEventListener('click', function(){
let bz=new BroadcastChannel('bez');
let hi,wi;
hi=window.innerHeight;
wi=window.innerWidth;
hi=Math.round(hi);
wi=window.innerWidth;
wi=Math.round(wi);
document.getElementById("ihig").innerHTML=hi;
document.getElementById("circle").height=hi;
document.getElementById("circle").width=wi;
bz.postMessage({data: 222});
});
);
return 1;
}
