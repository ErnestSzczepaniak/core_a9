# ---------------------------------------------| config |--------------------------------------------- #

set(platform                    target)

set(type                        debug)

set(version_major               1)
set(version_minor               0)
set(version_revision            0)

option(dump ""                  on)
option(image ""                 on)
option(documentation ""         off)

# ---------------------------------------------| project |--------------------------------------------- #

set(name_library                core_a9)

set(name_executable             executable.elf)

set(dependency_internal_common  )
set(dependency_internal_target  )
set(dependency_internal_host    )

set(dependency_external_common  )
set(dependency_external_target  )
set(dependency_external_host    )

set(dependency_scope            PRIVATE)

# ---------------------------------------------| target |--------------------------------------------- #

set(architecture                v7a)
set(gic                         pl390)
set(core                        a9)
set(family                      c5)

set(board                       de10standard)

set(memory                      ocram)

set(sdram_start                 0x00000000)
set(sdram_size                  1024M)
set(sdram_size_stack            2M)
set(sdram_size_pool             512M)

set(ocram_start                 0xffe00000)
set(ocram_size                  256K)
set(ocram_size_stack            16K)
set(ocram_size_pool             0)

