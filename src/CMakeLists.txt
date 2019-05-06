add_library( YetAnotherSLAMlib SHARED
    frame.cpp
    YAMLParser.cpp
    camera.cpp
    dataloader/fireburg_dataloader.cpp
)

target_link_libraries( YetAnotherSLAMlib
    ${THIRD_PARTY_LIBS}
)

add_executable( YetAnotherSLAM main.cpp)
target_link_libraries( YetAnotherSLAM YetAnotherSLAMlib )


