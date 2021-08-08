#include <agl.h>

namespace AbyssCore{

    PFNGLCREATESHADERPROC GLCreateShader;
    PFNGLCREATEPROGRAMPROC GLCreateProgram;
    PFNGLSHADERSOURCEPROC GLShaderSource;
    PFNGLCOMPILESHADERPROC GLCompileShader;
    PFNGLGETSHADERIVPROC GLGetShaderiv;
    PFNGLGETPROGRAMIVPROC GLGetProgramiv;
    PFNGLGETSHADERINFOLOGPROC GLGetShaderInfoLog;
    PFNGLGETPROGRAMINFOLOGPROC GLGetProgramInfoLog;
    PFNGLATTACHSHADERPROC GLAttachShader;
    PFNGLLINKPROGRAMPROC GLLinkProgram;
    PFNGLDELETESHADERPROC GLDeleteShader;
    PFNGLUSEPROGRAMPROC GLUseProgram;
    PFNGLUNIFORM1IPROC GLUniform1i;
    PFNGLUNIFORM1FPROC GLUniform1f;
    PFNGLUNIFORM4FPROC GLUniform4f;
    PFNGLGETUNIFORMLOCATIONPROC GLGetUniformLocation;
    PFNGLGENVERTEXARRAYSPROC GLGenVertexArrays;
    PFNGLDELETEVERTEXARRAYSPROC GLDeleteVertexArrays;
    PFNGLGENBUFFERSPROC GLGenBuffers;
    PFNGLDELETEBUFFERSPROC GLDeleteBuffers;
    PFNGLBINDVERTEXARRAYPROC GLBindVertexArray;
    PFNGLBINDBUFFERPROC GLBindBuffer;
    PFNGLBUFFERDATAPROC GLBufferData;
    PFNGLVERTEXATTRIBPOINTERPROC GLVertexAttribPointer;
    PFNGLENABLEVERTEXATTRIBARRAYPROC GLEnableVertexAttribArray;
    PFNGLGENFRAMEBUFFERSPROC GLGenFramebuffers;
    PFNGLDELETEFRAMEBUFFERSPROC GLDeleteFramebuffers;
    PFNGLBINDFRAMEBUFFERPROC GLBindFramebuffer;
    PFNGLFRAMEBUFFERTEXTURE2DPROC GLFramebufferTexture2D;
    PFNGLGENRENDERBUFFERSPROC GLGenRenderbuffers;
    PFNGLBINDRENDERBUFFERPROC GLBindRenderbuffer;
    PFNGLRENDERBUFFERSTORAGEPROC GLRenderbufferStorage;
    PFNGLFRAMEBUFFERRENDERBUFFERPROC GLFramebufferRenderbuffer;
    PFNGLCHECKFRAMEBUFFERSTATUSPROC GLCheckFramebufferStatus;
    PFNGLGENERATEMIPMAPPROC GLGenerateMipmap;

    Shader* controlShader;
    Shader* textureShader; 
    Shader* colorShader;

    bool GLInit(SDL_GLContext& context, SDL_Window* window){
        context = SDL_GL_CreateContext(window);

#ifdef WINDOWS
        GLCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
        GLCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
        GLShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
        GLCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
        GLGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
        GLGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
        GLGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
        GLGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
        GLAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
        GLLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
        GLDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
        GLUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
        GLUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
        GLUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
        GLUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
        GLGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
        GLGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
        GLDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
        GLGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
        GLDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
        GLBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
        GLBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
        GLBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
        GLVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
        GLEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
        GLGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
        GLDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
        GLBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
        GLFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
        GLGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
        GLBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
        GLRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
        GLFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
        GLCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
        GLGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
#endif

        controlShader = new Shader();
        controlShader->Load(new AString("shaders/controlVertex.glsl"), new AString("shaders/controlFragment.glsl"));

        textureShader = new Shader();
        textureShader->Load(new AString("shaders/textureVertex.glsl"), new AString("shaders/textureFragment.glsl"));

        colorShader = new Shader();
        colorShader->Load(new AString("shaders/colorVertex.glsl"), new AString("shaders/colorFragment.glsl"));

        SDL_GL_SetSwapInterval(1);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if(GLGetError())
            return false;

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        if(GLGetError())
            return false;

        return true;
    }

    bool GLGetError(){
        auto error = GL_NO_ERROR;
        error = glGetError();
        if(error != GL_NO_ERROR){
            printf("Error! %s\n", gluErrorString(error));
            return true;
        }

        return false;
    }

    aFPoint3 GLScreenToNormal(aPoint3 pos){
        float x_mid = screen_width / 2;
        float y_mid = screen_height / 2;

        float x = (-(x_mid - pos.x)) / x_mid;
        // float r = -(x_mid - (rect.x + rect.w)) / x_mid;
        float y = (y_mid - pos.y) / y_mid;
        // float b = (y_mid - (rect.y + rect.h)) / y_mid;
        float z = (float)pos.z;

        return aFPoint3({x, y, z});
    }

    aFColor GLConvertColor(aColor color){
        float r = (float)color.r / (float)255;
        float g = (float)color.g / (float)255;
        float b = (float)color.b / (float)255;
        float a = (float)color.a / (float)255;

        return aFColor({r, g, b, a});
    }

    Vertex* GLCreateRectArray(SDL_Rect rect, aColor color){
        aPoint3 v1 = {rect.x, rect.y + rect.h, 0};
        aPoint3 v2 = {rect.x, rect.y, 0};
        aPoint3 v3 = {rect.x + rect.w, rect.y, 0};
        aPoint3 v4 = {rect.x + rect.w, rect.y + rect.h, 0};

        aFPoint3 nv1 = GLScreenToNormal(v1);
        aFPoint3 nv2 = GLScreenToNormal(v2);
        aFPoint3 nv3 = GLScreenToNormal(v3);
        aFPoint3 nv4 = GLScreenToNormal(v4);

        aFColor ncolor = GLConvertColor(color);

        Vertex* vertices = (Vertex*)malloc(sizeof(Vertex) * 4);
        vertices[0] = {nv1, ncolor, {0, 0}};
        vertices[1] = {nv2, ncolor, {0, 1}};
        vertices[2] = {nv3, ncolor, {1, 1}};
        vertices[3] = {nv4, ncolor, {1, 0}};

        return vertices;
    }

    Vertex* GLCreateLineArray(aPair pairs, aColor color){
        aFPoint3 nv1 = GLScreenToNormal(aPoint3({pairs.x1, pairs.y1, 0}));
        aFPoint3 nv2 = GLScreenToNormal(aPoint3({pairs.x2, pairs.y2, 0}));

        aFColor ncolor = GLConvertColor(color);

        Vertex* vertices = (Vertex*)malloc(sizeof(Vertex) * 2);
        vertices[0] = {nv1, ncolor, {0, 0}};
        vertices[1] = {nv2, ncolor, {0, 0}};

        return vertices;
    }

    void GLCreateVertexObjects(Vertex* vertices, int size, unsigned int &VAO, unsigned int &VBO){
        GLGenVertexArrays(1, &VAO);
        GLGenBuffers(1, &VBO);

        GLBindVertexArray(VAO);
        GLBindBuffer(GL_ARRAY_BUFFER, VBO);

        float* fvertices = (float*)malloc(sizeof(float) * size * VERTEX_PARAMS);

        for(int i = 0; i < size; i++){
            fvertices[i * VERTEX_PARAMS + 0] = vertices[i].pos.x;
            fvertices[i * VERTEX_PARAMS + 1] = vertices[i].pos.y;
            fvertices[i * VERTEX_PARAMS + 2] = vertices[i].pos.z;
            fvertices[i * VERTEX_PARAMS + 3] = vertices[i].color.r;
            fvertices[i * VERTEX_PARAMS + 4] = vertices[i].color.g;
            fvertices[i * VERTEX_PARAMS + 5] = vertices[i].color.b;
            fvertices[i * VERTEX_PARAMS + 6] = vertices[i].color.a;
            fvertices[i * VERTEX_PARAMS + 7] = vertices[i].texPos.x;
            fvertices[i * VERTEX_PARAMS + 8] = vertices[i].texPos.y;
            // aPoint globPos = {arrayPtr[i].pos.x + array.x, arrayPtr[i].pos.y + array.y};

            // aFPoint normalCoord = GLConvertToNormal(globPos);
            // aFColor normalColor = GLConvertColor(arrayPtr[i].color);

            // vertices[0 + i * 8] = normalCoord.x;
            // vertices[1 + i * 8] = normalCoord.y;
            // vertices[2 + i * 8] = arrayPtr->texPos.x;
            // vertices[3 + i * 8] = arrayPtr->texPos.y;
            // vertices[4 + i * 8] = normalColor.r;
            // vertices[5 + i * 8] = normalColor.g;
            // vertices[6 + i * 8] = normalColor.b;
            // vertices[7 + i * 8] = normalColor.a;
        }

        GLBufferData(GL_ARRAY_BUFFER, sizeof(float) * size * VERTEX_PARAMS, fvertices, GL_STATIC_DRAW);

        GLVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_PARAMS * sizeof(float), (void*)0);
        GLEnableVertexAttribArray(0);

        GLVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_PARAMS * sizeof(float), (void*)(3 * sizeof(float)));
        GLEnableVertexAttribArray(1);

        GLVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, VERTEX_PARAMS * sizeof(float), (void*)(7 * sizeof(float)));
        GLEnableVertexAttribArray(2);

        GLBindVertexArray(0);
        GLBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    // void GLDrawVertices(GLenum mode, int vnumber){
    //     glDrawArrays(mode, 0, vnumber);
    // }

    void GLDestroyVertexObjects(unsigned int VAO, unsigned int VBO){
        GLBindBuffer(GL_ARRAY_BUFFER, 0);
        GLBindVertexArray(0);

        GLDeleteVertexArrays(1, &VAO);
        GLDeleteBuffers(1, &VBO);
    }

    unsigned int GLCreate2DTexture(void* data, int width, int height, int colorMode, int filtration){
        unsigned int texture;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtration);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtration);

        glTexImage2D(GL_TEXTURE_2D, 0, colorMode, width, height, 0, colorMode, GL_UNSIGNED_BYTE, data);
        GLGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

        return texture;
    }

    void GLBind2DTexture(unsigned int texture){
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    Shader::Shader(){
        
    }

    void Shader::Use(){
        GLUseProgram(ID);
    }

    void Shader::Load(AString* vpath, AString* fpath){
        
        ifstream vfile(vpath->ToChars(), ios::binary);
        ifstream ffile(fpath->ToChars(), ios::binary);

        if(!vfile.is_open() || !ffile.is_open())
            return;

        delete vpath;
        delete fpath;

        stringstream vss;
        stringstream fss;

        vss << vfile.rdbuf();
        fss << ffile.rdbuf();

        string vs = vss.str();
        string fs = fss.str();

        vfile.close();
        ffile.close();

        const char* vShaderCode = vs.c_str();
        const char* fShaderCode = fs.c_str();

        unsigned int vertex, fragment;
        int success;
        char info[512];

        vertex = GLCreateShader(GL_VERTEX_SHADER);

        GLShaderSource(vertex, 1, &vShaderCode, NULL);

        GLCompileShader(vertex);

        if(!GetError(vertex, VSHADER))
            return;

        fragment = GLCreateShader(GL_FRAGMENT_SHADER);

        GLShaderSource(fragment, 1, &fShaderCode, NULL);

        GLCompileShader(fragment);

        if(!GetError(fragment, FSHADER))
            return;

        ID = GLCreateProgram();
        GLAttachShader(ID, vertex);
        GLAttachShader(ID, fragment);
        GLLinkProgram(ID);

        GetError(ID, PROGRAM);
        GLDeleteShader(vertex);
        GLDeleteShader(fragment);
    }

    bool Shader::GetError(int proc, Uint32 type){
        int success;
        char infoLog[512];

        switch(type){
            case PROGRAM:
                GLGetProgramiv(proc, GL_LINK_STATUS, &success);
            break;
            case VSHADER:
            case FSHADER:
                GLGetShaderiv(proc, GL_COMPILE_STATUS, &success);
            break;
        }

        if(!success){
            switch(type){
                case PROGRAM:
                    GLGetProgramInfoLog(proc, 512, NULL, infoLog);
                    printf("Some error in linking shader program! %s\n", infoLog);
                break;
                case VSHADER:
                    GLGetShaderInfoLog(proc, 512, NULL, infoLog);
                    printf("Vertex shader compile error! %s\n", infoLog);
                break;
                case FSHADER:
                    GLGetShaderInfoLog(proc, 512, NULL, infoLog);
                    printf("Fragment shader compile error! %s\n", infoLog);
                break;
            }

            return false;
        }

        return true;
    }

    void Shader::SetInt1(AString name, int i){
        GLUniform1i(GLGetUniformLocation(ID, name.ToChars()), i);
    }

    void Shader::SetFloat4(AString name, float x, float y, float z, float w){
        GLUniform4f(GLGetUniformLocation(ID, name.ToChars()), x, y, z, w);
    }
}