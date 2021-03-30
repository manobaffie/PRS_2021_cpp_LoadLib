// #include "LoadLib.hpp"

template <class T>
LoadLib<T>::LoadLib(std::string p) : path(p)
{
    void *lib = dlopen(this->path.c_str(), RTLD_LAZY | RTLD_GLOBAL);

    if (!lib)
        std::cerr << "[ERROR " << this->path << "] : Cannot load library" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;
    dlerror();

    this->create_l = (T *(*)()) dlsym(lib, "create");

    const char* dlsym_error = dlerror();
    if (dlsym_error)
        std::cerr << "[ERROR " << this->path << "] : Cannot load symbol create" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;

    this->destroy_l = (void (*)(T *)) dlsym(lib, "destroy");

    dlsym_error = dlerror();
    if (dlsym_error)
        std::cerr << "[ERROR " << this->path << "] : Cannot load symbol destroy" << "\n[ERROR Lib] : ->" << dlerror() <<  std::endl;

    // lib* l = create_lib();
    this->create_l->printHello();

    // l->printHello();

    // destroy_lib(l);
    // dlclose(lib);
}

template <class T>
LoadLib<T>::~LoadLib()
{
}
