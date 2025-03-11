#NOT USED AT THE MOMENT

cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Enable CUDA support
enable_language(CUDA)

# Add CUDA compiler flags
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11")

# Add your CUDA source files
add_executable(MyExecutable main.cu)

# Link against CUDA libraries
target_link_libraries(MyExecutable ${CUDA_LIBRARIES})
