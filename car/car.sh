g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-elide-constructors -g -o car.out car.cpp && ./car.out

# Used for inspecting assembly
# g++ -std=c++17 -O3 -S -Wall -fsanitize=address -fsanitize=undefined -fno-elide-constructors -g car.cpp
# -S stops the compilation after producing assembly.