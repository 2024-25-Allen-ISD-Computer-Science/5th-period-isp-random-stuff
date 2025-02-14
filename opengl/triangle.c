#include <GL/glew.h> // extensions!!!!!
#include <GLFW/glfw3.h> // allows you to make windows

const char* vShaderSrc = "#version 330 core\n" // glsl version 3.3 (the coolest version)
                         "layout (location=0) in vec3 aPos;\n" // shader will recieve each vertex
                         "layout (location=1) in vec3 aColor;\n" // shader will recieve each colo
                         "out vec3 color;\n" // holds color value for each vertex, out means that shader will make the value and pass it to frag
                         "void main(){ gl_Position=vec4(aPos,1.0); color=aColor; }"; // set vertex position to gl_position and passes color to frag shader

const char* fShaderSrc = "#version 330 core\n" // same as other thing
                         "in vec3 color;\n" // recieve the outputted color value from shader
                         "out vec4 FragColor;\n" // output the fragcolor
                         "void main(){ FragColor=vec4(color,1.0); }"; // set frag color to in color, 1 for each vertex

float vertices[] = { 
    0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // first three floars for each one is position (xyz), next 3 are color (rgb)
   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
    0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f  
};

int compileShader(GLenum type, const char* src) {
    int shader = glCreateShader(type); // make object of param type
    glShaderSource(shader, 1, &src, NULL); // set source code for shader
    glCompileShader(shader); // compile shader from source
    return shader; // return
}

int main() {
    glfwInit(); // init the window
    GLFWwindow* win = glfwCreateWindow(800, 600, "tri gradient", NULL, NULL); // make the window
    glfwMakeContextCurrent(win); // make this the main window for opengl
    glewInit(); // finish the init

    int VAO, VBO; // vertex array object and vertex buffer object

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind object to thing that holds vertex data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // fill the buffer with vertex data from the verticies array

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // how opengl should use vertex data for location 0
    glEnableVertexAttribArray(0); // enable vertex attribute array for position

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    int shaderProg = glCreateProgram(); // make shader program
    glAttachShader(shaderProg, compileShader(GL_VERTEX_SHADER, vShaderSrc));   // attach the compiled vertex shader to program
    glAttachShader(shaderProg, compileShader(GL_FRAGMENT_SHADER, fShaderSrc));
    glLinkProgram(shaderProg); // link the shaders to make complete program

    while (1) {
        glClear(GL_COLOR_BUFFER_BIT); // clear screen
        glUseProgram(shaderProg); // use shader program
        glDrawArrays(GL_TRIANGLES, 0, 3); // draw triangles
        glfwSwapBuffers(win); // move to next frame
    }

    glfwTerminate(); // bye
    return 0;
}

