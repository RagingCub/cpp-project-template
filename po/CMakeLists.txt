find_package(Gettext)

if (GETTEXT_FOUND)
    #set(GETTEXT_MSGMERGE_EXECUTABLE :)

    set(domain ${PROJECT_NAME})
    set(build_directory ${CMAKE_BINARY_DIR}/po)
    set(pot_file ${build_directory}/${domain}.pot)
    set(potfiles_file ${build_directory}/POTFILES)

    file(MAKE_DIRECTORY ${build_directory})
    configure_file(POTFILES.in ${potfiles_file})

    add_custom_command(
            OUTPUT ${pot_file}
            DEPENDS ${potfiles_file}
            COMMAND xgettext
            --default-domain=${domain}
            --add-comments
            #--msgid-bugs-address="http://bugs.webkit.org"
            --files-from=${potfiles_file}
            --package-version=${PROJECT_VERSION}
            --package-version=${PROJECT_NAME}
            --keyword=gettext
            --keyword=ngettext
            --from-code=UTF-8
            -o ${pot_file}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..
    )
    add_custom_target(potfile DEPENDS ${pot_file})

    file(GLOB po_files *.po)
    gettext_create_translations(${pot_file} ALL ${po_files})
    add_dependencies(translations potfile)

    set(mo_files)
    foreach (po_file ${po_files})
        get_filename_component(lang ${po_file} NAME_WE)
        set(mo_file ${PACKAGE_LOCALEDIR}/${lang}/LC_MESSAGES/${domain}.mo)
        add_custom_command(
                OUTPUT ${mo_file}
                DEPENDS translations
                COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${lang}.gmo ${mo_file}
        )
        list(APPEND mo_files ${mo_file})
    endforeach ()

    if (${CMAKE_BUILD_TYPE} MATCHES Debug)
        add_custom_target(move_translations DEPENDS ${mo_files})
        add_dependencies(${PROJECT_NAME} move_translations)
    endif ()

    # To choose language, LANG environment variable has to be set : LANG=fr_CA.utf8
endif ()
