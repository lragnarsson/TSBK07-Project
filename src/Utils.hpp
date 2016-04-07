#ifndef UTILS_H
#define UTILS_H

#ifdef __linux__
  #include <GL/glew.h>
#endif

#ifdef __APPLE__
  #include <OpenGL/gl3.h>
#endif

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp> // glm::pi
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Containers.hpp"

  /* Upload all light information to the GPU */
void upload_lights(const GLuint shader_program, const std::vector<Light*> &loaded_lights);

/* Initialize SDL and GLEW (on Linux) and creates an OpenGL context within a window */
bool sdl_init(const GLuint screen_width, const GLuint screen_height,
              SDL_Window *&main_window, SDL_GLContext &main_context);

/* Quits SDL properly */
void sdl_quit(SDL_Window* main_window, SDL_GLContext &main_context);

/* Prints SDL errors if any exist */
void sdl_check_error(const int line);

/* Print OpenGL major and minor versions */
void sdl_print_attributes();

/* Loads, compiles and activates vertex and fragment shaders */
GLuint load_shaders(const GLchar* vertex_file_path, const GLchar* fragment_file_path);

#endif // UTILS_H
