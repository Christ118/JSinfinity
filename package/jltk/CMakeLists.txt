add_library (__init__ SHARED  jltk.cpp buttonobject.cpp imageobject.cpp tooltipobject.cpp boxobject.cpp spinnerobject.cpp progressobject.cpp)

find_package(PkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(V8 "v8")
  if (V8_FOUND)    
    target_link_libraries(__init__  ${V8_LIBRARIES} v8_libplatform)
    add_definitions(${V8_CFLAGS} ${V8_CFLAGS_OTHER})
  endif()
endif()

