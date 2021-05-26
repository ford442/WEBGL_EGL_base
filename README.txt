Imperativement modifier le env.bat du ./project/ pour adapter à vos nouveaux chemins.
Egalement, j'utilise VSCODE et le .vscode contient des chemins à modifier :
- c_cpp_properties.json
- tasks.json

Je compile actuellement ce projet avec Mingw64 du MSYS2.
ATTENTION, selon emscripten se désigne comme une platform purement 32-bit.
https://emscripten.org/docs/compiling/Building-Projects.html

Des problèmes de compatibilités peuvent survenir en compilant dans l'architecture 64 bit.
Je recommande donc de passer à MingW, bien que le projet ait été abandonné ou alors de passer à un autre compilateur.
Les compilateurs MINGW et MINGW64 sont fonctionnels pour ce projet.

///////
 
Compiler le projet !

- ./cmake_generate.bat 
- ./cmake_build.bat 

Pour le déploiement du bin, j'utilise : python -m http.server 
qui est la commande plus récente de SimpleHTTPServer.