cmake_minimum_required(VERSION 3.8)
project(rom_robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation_cmake REQUIRED)
find_package(std_msgs REQUIRED)

# ===================================== START ROM CODE ================================= #
include_directories(include)

# ---------------- topic library ----------------
add_library(topics_library SHARED
  src/talker.cpp
)
# target_compile_definitions(${library}
#   PRIVATE "ROM_COMPOSITION_NODE_BUILDING_DLL")
ament_target_dependencies(topics_library
    "rclcpp"
    "rclcpp_components"
    "std_msgs"
)
rclcpp_components_register_node(
  topics_library
  PLUGIN "rom_robot::Talker"
  EXECUTABLE talker
)

# ------------ publisher component --------------
add_library(publisher_component SHARED
  src/publisher_component.cpp
)
# target_compile_definitions(talker_component
#   PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(publisher_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs")
rclcpp_components_register_node(
  publisher_component
  PLUGIN "rom_robot::Mypublisher"
  EXECUTABLE publisherrr                              # :)
  )

# ------------ Listener component --------------
add_library(listenerr_component SHARED                # :)
  src/listener_component.cpp
)
# target_compile_definitions(talker_component
#   PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(listenerr_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs")
rclcpp_components_register_node(
  listenerr_component
  PLUGIN "rom_robot::Listener"
  EXECUTABLE listener
  )

# ---------------- INSTALL -----------------
install(TARGETS
  topics_library
  publisher_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# ===================================== END ROM CODE ================================= #
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
