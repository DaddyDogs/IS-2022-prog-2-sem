#include "RubiksCube.h"

void set_color(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color) {
        case 0:
            SetConsoleTextAttribute(hConsole, 7);
            break;
        case 1:
            SetConsoleTextAttribute(hConsole, 6);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 2);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 4);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 1);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, 14);
            break;
        default:
            SetConsoleTextAttribute(hConsole, 0);
    }
}
RubiksCube::RubiksCube() {
    memcpy(Cube, Correct_Cube, sizeof Correct_Cube);
}


void RubiksCube::read(const char *filename) { //первая строчка у нижней грани - стык с передней, последняя строчка у верхней - стык с передней
    std::ifstream in(filename);
    for (int column = 0; column < 3; ++column){
        for (int line = 0; line < 3; ++line){
            in >> Cube[0][column][line];
        }
    }
    for (int line = 0; line < 3; ++line){
        for (int column = 0; column < 12  ; ++column){
            in >> Cube[column / 3 + 1][line][column % 3];
        }
    }
    for (int column = 0; column < 3; ++column){
        for (int line = 0; line < 3; ++line){
            in >> Cube[5][column][line];
        }
    }
    std::cout << "Configuration's save was completed successfully" << "\n";
}

std::ostream &operator<<(std::ostream &out, RubiksCube &cube) {
    out << "Current configuration:\n      ";
    for (int line = 0; line < 3; ++line){
        for (int column = 0; column < 3; ++column){
            set_color(cube.Cube[0][line][column]);
            out << cube.Cube[0][line][column] << " ";
        }
        if (line != 2) out << "\n      ";
        else out << "\n";
    }
    for (int line = 0; line < 3; ++line){
        for (int column = 0; column < 12  ; ++column){
            set_color(cube.Cube[column / 3 + 1][line][column % 3]);
            out << cube.Cube[column / 3 + 1][line][column % 3] << " ";
        }
        out << "\n";
    }
    out << "      ";
    for (int line = 0; line < 3; ++line){
        for (int column = 0; column < 3; ++column){
            set_color(cube.Cube[5][line][column]);
            out << cube.Cube[5][line][column] << " ";
        }
        out << "\n      ";
    }
    return out;
}

//void RubiksCube::flat_rotation(int flat_number, bool direction) {
//     int buffer[3][3];
//     if (direction) {
//         int i = 0;
//         for (int j = i; j < 2 - i; ++j){
//             int temp = Cube[flat_number][i][j];
//             Cube[flat_number][i][j] = Cube[flat_number][2 - j][i];
//             Cube[flat_number][2 - j][i] = Cube[flat_number][2 - i][2 - j];
//             Cube[flat_number][2 - i][2 - j] = Cube[flat_number][j][2 - i];
//             Cube[flat_number][j][2 - i] = temp;
//         }
//     }
//     else {
//         for (int i = 0; i < 9; ++i) {
//             buffer[i / 3][i % 3] = Cube[flat_number][i % 3][2 - i / 3];
//         }
//     }
//}

void RubiksCube::flat_rotation(int flat_number, bool direction) {
    int buffer[3][3];
    if (!direction) {
        for (int i = 0; i < 9; i++) {
            buffer[i / 3][i % 3] = Cube[flat_number][i % 3][2 - i / 3];
        }
    } else {
        for (int i = 0; i < 9; i++) {
            buffer[i % 3][i / 3] = Cube[flat_number][2 - i / 3][i % 3];
        }
    }

    for (int i = 0; i < 9; i++) {
        Cube[flat_number][i / 3][i % 3] = buffer[i / 3][i % 3];
    }
}

void RubiksCube::top_bottom_rotation(int line, bool direction) {
    if (direction) {
        int buffer1[3];
        memcpy(buffer1, Cube[1][line], sizeof Cube[1][line]);
        for (int i = 1; i < 4; ++i){
            memcpy(Cube[i][line], Cube[i + 1][line], sizeof Cube[i][line]);
        }
        memcpy(Cube[4][line], buffer1, sizeof buffer1);
    }
    else {
        int buffer1[3];
        memcpy(buffer1, Cube[4][line], sizeof Cube[4][line]);
        for (int i = 4; i > 1; --i) {
            memcpy(Cube[i][line], Cube[i - 1][line], sizeof Cube[i][line]);
        }
        memcpy(Cube[1][line], buffer1, sizeof buffer1);

    }
}

void RubiksCube::right_rotation(int column){
    int buffer1[3];
    for (int i = 0; i < 3; ++i){
        buffer1[i] = Cube[2][i][column];
    }
    int a = Cube[5][2][column]; int b = Cube[4][2][2 - column];
    for (int i = 0; i < 3; ++i){
        Cube[2][i][column] = Cube[5][i][column];
        Cube[5][2 - i][column] = Cube[4][i][2 - column];
        Cube[4][2 - i][2 - column] = Cube[0][i][column];
        Cube[0][i][column] = buffer1[i];
    }
    Cube[2][2][column] = a; Cube[5][0][column] = b;
}

void RubiksCube::left_rotation(int column){
    int buffer1[3];
    for (int i = 0; i < 3; ++i){
        buffer1[i] = Cube[5][i][column];
    }
    int a = Cube[0][2][column]; int b = Cube[4][2][2 - column];
    for (int i = 0; i < 3; ++i){
        Cube[5][i][column] = Cube[2][i][column];
        Cube[2][i][column] = Cube[0][i][column];
        Cube[0][2 - i][column] = Cube[4][i][2 - column];
        Cube[4][2 - i][2 - column] = buffer1[i];
    }
    Cube[2][2][column] = a; Cube[0][0][column] = b;
}


void RubiksCube::U() {
    flat_rotation(0, true);
    top_bottom_rotation(0, true);
//    Cube[0][0][0] = Cube[0][2][0];
//    Cube[0][0][1] = Cube[0][1][0];
//    Cube[0][0][2] = buffer1[0];
//    Cube[0][1][0] = Cube[0][2][1];
//    Cube[0][2][0] = Cube[0][2][2];
//    Cube[0][2][1] = Cube[0][1][2];
//    Cube[0][2][2] = buffer1[2];
//    Cube[0][1][2] = buffer1[1];
}
void RubiksCube::U_() {
    flat_rotation(0, false);
    top_bottom_rotation(0, false);
}
void RubiksCube::U2() {
    U(); U();
}


void RubiksCube::D() {
    flat_rotation(5, true);
    top_bottom_rotation(2, false);
}
void RubiksCube::D_() {
    flat_rotation(5, false);
    top_bottom_rotation(2, true);
}
void RubiksCube::D2() {
    D(); D();
}


void RubiksCube::R() {
    flat_rotation(3, true);
    right_rotation(2);
}
void RubiksCube::R_() {
    flat_rotation(3, false);
    left_rotation(2);
}
void RubiksCube::R2() {
    R(); R();
}


void RubiksCube::L() {
    flat_rotation(1, true);
    left_rotation(0);
}
void RubiksCube::L_() {
    flat_rotation(1, false);
    right_rotation(0);
}
void RubiksCube::L2() {
    L(); L();
}


void RubiksCube::face_back_rotation(int x, int bias) {
    int buffer[3];
    memcpy(buffer, Cube[0][x], sizeof Cube[0][x]);
    int a;
    if (x == 2 and bias == 2){
        a = Cube[5][0][0];
    }
    else {
        a = Cube[5 - 2 * x][2 - x][x - bias];
    }
    int b;
    if (x == 2 and bias == 0){
        b = Cube[3][0][0];
    }
    for(int i = 0; i < 3; ++i){
        Cube[0][x][i] = Cube[1 + (2 - x) + bias][std::abs(-i + x - bias)][2 - bias];
        Cube[1 + (2 - x) + bias][i][2 - bias] = Cube[5][2 - x][std::abs(bias - i + (2 - x))];
        Cube[5][(2 - x)][i] = Cube[1 + x - bias][std::abs(-i + x - bias)][0 + bias];
        Cube[1 + x - bias][i][0 + bias] = buffer[std::abs(bias - i + (2 - x))];
    }
    if (x == 2 and bias == 2){
        Cube[3][2][0] = a;
    }
    else Cube[int(3 - 1.5 * x)][2][2] = a;
    if (x == 2 and bias == 0){
        Cube[5][0][2] = b;
    }
}

void RubiksCube::F() {
    flat_rotation(2, true);
    face_back_rotation(2, 0);
//    int buffer[3];
//    memcpy(buffer, Cube[0][2], sizeof Cube[0][2]);
//    int a = Cube[1][0][2]; int b = Cube[3][0][0];
//    for(int i = 0; i < 3; ++i){
//        Cube[0][2][i] = Cube[1][2 - i][2];
//        Cube[1][i][2] = Cube[5][0][i];
//        Cube[5][0][i] = Cube[3][2 - i][0];
//        Cube[3][i][0] = buffer[i];
//    }
//    Cube[0][2][2] = a; Cube[5][0][2] = b;
}
void RubiksCube::F_() {
    flat_rotation(2, false);
//    int buffer[3];
//    memcpy(buffer, Cube[0][2], sizeof Cube[0][2]);
//    int a = Cube[5][0][0];
//    for(int i = 0; i < 3; ++i){
//        Cube[0][2][i] = Cube[3][i][0];
//        Cube[3][i][0] = Cube[5][0][2 - i];
//        Cube[5][0][i] = Cube[1][i][2];
//        Cube[1][i][2] = buffer[2 - i];
//    }
//    Cube[3][2][0] = a;
    face_back_rotation(2, 2);
}
void RubiksCube::F2() {
    F(); F();
}

void RubiksCube::B() {
      flat_rotation(4, true);
//    int buffer[3];
//    memcpy(buffer, Cube[0][0], sizeof Cube[0][0]);
//    int a = Cube[5][2][0];
//    for(int i = 0; i < 3; ++i){
//        Cube[0][0][i] = Cube[3][i][2];
//        Cube[3][i][2] = Cube[5][2][2 - i];
//        Cube[5][2][i] = Cube[1][i][0];
//        Cube[1][i][0] = buffer[2 - i];
//    }
//    Cube[3][2][2] = a;
    face_back_rotation(0, 0);
}
void RubiksCube::B_() {
    flat_rotation(4, false);
    int buffer[3];
    memcpy(buffer, Cube[0][0], sizeof Cube[0][0]);
    int a = Cube[1][0][0]; int b = Cube[3][0][2];
    for(int i = 0; i < 3; ++i){
        Cube[0][0][i] = Cube[1][2 - i][0];
        Cube[1][i][0] = Cube[5][2][i];
        Cube[5][2][i] = Cube[3][2 - i][2];
        Cube[3][i][2] = buffer[i];
    }
    Cube[0][0][2] = a; Cube[5][2][2] = b;
//    face_back_rotation(0, 2);
}
void RubiksCube::B2() {
    B(); B();
}


void RubiksCube::inside_rotation(bool direction){
    int buffer[3][3];
    memcpy(buffer, Cube[1], sizeof Cube[1]);
    memcpy(Cube[1], Cube[5], sizeof Cube[0]);
    memcpy(Cube[5], Cube[3], sizeof Cube[3]);
    memcpy(Cube[3], Cube[0], sizeof Cube[5]);
    memcpy(Cube[0], buffer, sizeof buffer);
    for (int i = 0; i < 6; ++i) {
        flat_rotation(i, i - 4);
    }
    top_bottom_rotation(1, direction);
    memcpy(buffer, Cube[1], sizeof Cube[1]);
    memcpy(Cube[1], Cube[0], sizeof Cube[0]);
    memcpy(Cube[0], Cube[3], sizeof Cube[3]);
    memcpy(Cube[3], Cube[5], sizeof Cube[5]);
    memcpy(Cube[5], buffer, sizeof buffer);
    for (int i = 0; i < 6; ++i) {
        flat_rotation(i, !(i - 4));
    }
}

void RubiksCube::M() {
    inside_rotation(true);
}
void RubiksCube::M_() {
    inside_rotation(false);
}
void RubiksCube::M2() {
    M(); M();
}

void RubiksCube::E() {
    top_bottom_rotation(1, false);
}
void RubiksCube::E_() {
    top_bottom_rotation(1, true);
}
void RubiksCube::E2() {
    E(); E();
}

void RubiksCube::S_rotation(bool direction) {
    int buffer[3][3];
    memcpy(buffer, Cube[0], sizeof Cube[1]);
    memcpy(Cube[0], Cube[4], sizeof Cube[0]);
    memcpy(Cube[4], Cube[5], sizeof Cube[3]);
    memcpy(Cube[5], Cube[2], sizeof Cube[5]);
    memcpy(Cube[2], buffer, sizeof buffer);
    flat_rotation(1, true);
    flat_rotation(3, false);
    flat_rotation(0, false);
    flat_rotation(0, false);
    flat_rotation(4, false);
    flat_rotation(4, false);
    top_bottom_rotation(1, direction);
    memcpy(buffer, Cube[2], sizeof Cube[1]);
    memcpy(Cube[2], Cube[5], sizeof Cube[0]);
    memcpy(Cube[5], Cube[4], sizeof Cube[3]);
    memcpy(Cube[4], Cube[0], sizeof Cube[5]);
    memcpy(Cube[0], buffer, sizeof buffer);
    flat_rotation(1, false);
    flat_rotation(3, true);
    flat_rotation(4, true);
    flat_rotation(4, true);
    flat_rotation(5, false);
    flat_rotation(5, false);
}
void RubiksCube::S() {
    S_rotation(false);
}
void RubiksCube::S_() {
    S_rotation(true);
}
void RubiksCube::S2() {
    S(); S();
}

void RubiksCube::first_step(std::vector<std::string> &answer) {
    int y = 0;
    while (y < 4) {
        if (Cube[2][0][1] == Cube[2][1][1] && Cube[0][2][1] == Cube[5][1][1]) {
            F();
            F();
            answer.emplace_back("F F ");
        } else if (Cube[3][0][1] == Cube[3][1][1] && Cube[0][1][2] == Cube[5][1][1]) {
            R();
            R();
            answer.emplace_back("R R ");
        }
            //Cube[1][2][1] == Cube[1][1][1]
        else if (Cube[4][0][1] == Cube[4][1][1] && Cube[0][0][1] == Cube[5][1][1]) {
            B();
            B();
            answer.emplace_back("B B ");
        }
        else if (Cube[1][0][1] == Cube[1][1][1] && Cube[0][1][0] == Cube[5][1][1]) {
            L();
            L();
            answer.emplace_back("L L ");
        }

            //Cube[0][0][1]  Cube[2][2][1] == Cube[1][1][1]
        else if (Cube[0][2][1] == Cube[2][1][1] && Cube[2][0][1] == Cube[5][1][1]) {
            U_();
            R_();
            F();
            R();
            answer.emplace_back("U' R' F R ");
        } else if (Cube[0][1][2] == Cube[3][1][1] && Cube[3][0][1] == Cube[5][1][1]) {
            U_();
            B_();
            R();
            B();
            answer.emplace_back("U' B' R B ");
        }else if (Cube[0][0][1] == Cube[4][1][1] && Cube[4][0][1] == Cube[5][1][1]) {
            U_();
            L_();
            B();
            L();
            answer.emplace_back("U' L' B L ");
        } else if (Cube[0][1][0] == Cube[1][1][1] && Cube[1][0][1] == Cube[5][1][1]) {
            U_();
            F_();
            L();
            F();
            answer.emplace_back("U' F' L F ");
        }  else if (Cube[2][1][2] == Cube[5][1][1]) {
            F_();
            U_();
            F();
            answer.emplace_back("F' U' F ");
        } else if (Cube[3][1][2] == Cube[5][1][1]) {
            R_();
            U_();
            R();
            answer.emplace_back("R' U' R ");
        }
            //Cube[1][1][0]
        else if (Cube[4][1][2] == Cube[5][1][1]) {
            B_();
            U_();
            B();
            answer.emplace_back("B' U' B ");
        } else if (Cube[1][1][2] == Cube[5][1][1]) {
            L_();
            U_();
            L();
            answer.emplace_back("L' U' L ");
        }
        else if (Cube[2][1][0] == Cube[5][1][1]) {
            F();
            U_();
            F_();
            answer.emplace_back("F U' F' ");
        } else if (Cube[3][1][0] == Cube[5][1][1]) {
            R();
            U_();
            R_();
            answer.emplace_back("R U' R' ");
        }
        else if (Cube[4][1][0] == Cube[5][1][1]) {
            B();
            U_();
            B_();
            answer.emplace_back("B U' B' ");
        } else if (Cube[1][1][0] == Cube[5][1][1]) {
            L();
            U_();
            L_();
            answer.emplace_back("L U' L' ");
        }else if (Cube[2][2][1] == Cube[5][1][1]) {
            F();
            F();
            U_();
            F();
            F();
            answer.emplace_back("F F U' F F ");
        } else if (Cube[3][2][1] == Cube[5][1][1]) {
            R();
            R();
            U_();
            R();
            R();
            answer.emplace_back("R R U' R R ");
        }
        else if (Cube[4][2][1] == Cube[5][1][1]) {
            B();
            B();
            U_();
            B();
            B();
            answer.emplace_back("B B U' B B ");
        } else if (Cube[1][2][1] == Cube[5][1][1]) {
            L();
            L();
            U_();
            L();
            L();
            answer.emplace_back("L L U' L L ");
        }else if (Cube[2][2][1] != Cube[2][1][1] && Cube[5][0][1] == Cube[5][1][1]) {
            F();
            F();
            U_();
            F();
            F();
            answer.emplace_back("F F U' F F ");
        } else if (Cube[3][2][1] != Cube[3][1][1] && Cube[5][1][2] == Cube[5][1][1]) {
            R();
            R();
            U_();
            R();
            R();
            answer.emplace_back("R R U' R R ");
        }
            //Cube[1][2][1] != Cube[1][1][1]
            //Cube[0][0][1] != Cube[1][1][1]
        else if (Cube[4][2][1] != Cube[4][1][1] && Cube[5][2][1] == Cube[5][1][1]) {
            B();
            B();
            U_();
            B();
            B();
            answer.emplace_back("B B U' B B ");
        } else if (Cube[1][2][1] != Cube[1][1][1] && Cube[5][1][0] == Cube[5][1][1]) {
            L();
            L();
            U_();
            L();
            L();
            answer.emplace_back("L L U' L L  ");
        }
        else {
            U();
            answer.emplace_back("U ");
            y++;
        }
    }
    answer.emplace_back("\n\n");
}

void RubiksCube::second_step(std::vector<std::string> &answer) {
    int k = 0;
    while (k < 4) {
        if (Cube[3][0][0] == Cube[3][1][1] && Cube[0][2][2] == Cube[2][1][1]
            && Cube[2][0][2] == Cube[5][1][1]) {
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            answer.emplace_back("5 * R U R' U' ");
        } else if (Cube[2][0][0] == Cube[2][1][1] && Cube[0][2][0] == Cube[1][1][1]
                   && Cube[1][0][2] == Cube[5][1][1]) {
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            answer.emplace_back("5 * F U F' U' ");
        } else if (Cube[4][0][0] == Cube[4][1][1] && Cube[0][0][2] == Cube[3][1][1]
                   && Cube[3][0][2] == Cube[5][1][1]) {

            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            answer.emplace_back("5 * B U B' U' ");
        } else if (Cube[1][0][0] == Cube[1][1][1] && Cube[0][0][0] == Cube[4][1][1]
                   && Cube[4][0][2] == Cube[5][1][1]) {
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();

            answer.emplace_back("5 * L U L' U' ");
        } else if (Cube[2][0][2] == Cube[2][1][1] && Cube[0][2][2] == Cube[3][1][1]
                   && Cube[3][0][0] == Cube[5][1][1]) {
            //Pif-Paf
            R();
            U();
            R_();
            U_();
            answer.emplace_back("R U R' U' ");
        } else if (Cube[1][0][2] == Cube[1][1][1] && Cube[0][2][0] == Cube[2][1][1]
                   && Cube[2][0][0] == Cube[5][1][1]) {

            F();
            U();
            F_();
            U_();

            answer.emplace_back("F U F' U' ");
        } else if (Cube[3][0][2] == Cube[3][1][1] && Cube[0][0][2] == Cube[4][1][1]
                   && Cube[4][0][0] == Cube[5][1][1]) {

            B();
            U();
            B_();
            U_();


            answer.emplace_back("B U B' U' ");
        } else if (Cube[4][0][2] == Cube[4][1][1] && Cube[0][0][0] == Cube[1][1][1]
                   && Cube[1][0][0] == Cube[5][1][1]) {

            L();
            U();
            L_();
            U_();

            answer.emplace_back("L U L' U' ");
        } else if (Cube[2][0][2] == Cube[3][1][1]
                   && Cube[0][2][2] == Cube[5][1][1]
                   && Cube[3][0][0] == Cube[2][1][1]) {

            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();

            answer.emplace_back("3 * R U R' U' ");
        } else if (Cube[1][0][2] == Cube[2][1][1]
                   && Cube[0][2][0] == Cube[5][1][1]
                   && Cube[2][0][0] == Cube[1][1][1]
            //&& Cube[0][2][1] == Cube[0][1][1]
            //&& Cube[5][2][1] == Cube[5][1][1]
                ) {

            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();

            answer.emplace_back("3 * F U F' U' ");
        } else if (Cube[3][0][2] == Cube[4][1][1]
                   && Cube[0][0][2] == Cube[5][1][1]
                   && Cube[4][0][0] == Cube[3][1][1]) {

            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();

            answer.emplace_back("3 * B U B' U' ");

        } else if (Cube[4][0][2] == Cube[1][1][1]
                   && Cube[0][0][0] == Cube[5][1][1]
                   && Cube[1][0][0] == Cube[4][1][1]) {
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            answer.emplace_back("3 * L U L' U' ");
        } else if (Cube[2][2][2] == Cube[5][1][1] && Cube[3][2][0] == Cube[2][1][1]) {

            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            answer.emplace_back("4 * R U R' U' ");
        } else if (Cube[1][2][2] == Cube[5][1][1]) {

            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            answer.emplace_back("4 * F U F' U' ");
        } else if (Cube[3][2][2] == Cube[5][1][1]) {

            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            answer.emplace_back("4 * B U B' U' ");
        } else if (Cube[4][2][2] == Cube[5][1][1]) {

            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();
            answer.emplace_back("4 * L U L' U'");
        } else if (Cube[3][2][0] == Cube[5][1][1]) {
            R();
            U();
            R_();
            U_();
            R();
            U();
            R_();
            U_();
            answer.emplace_back("2 * R U R' U' ");
        } else if (Cube[2][2][0] == Cube[5][1][1]) {

            F();
            U();
            F_();
            U_();
            F();
            U();
            F_();
            U_();
            answer.emplace_back("2 * F U F' U' ");
        } else if (Cube[4][2][0] == Cube[5][1][1]) {
            B();
            U();
            B_();
            U_();
            B();
            U();
            B_();
            U_();
            answer.emplace_back("2 * B U B' U' ");
        } else if (Cube[1][2][0] == Cube[5][1][1]) {
            L();
            U();
            L_();
            U_();
            L();
            U();
            L_();
            U_();

            answer.emplace_back("2 * L U L' U' ");
        } else if (Cube[5][0][0] == Cube[5][1][1]
                   && (Cube[2][2][0] != Cube[2][1][1] || Cube[1][2][2] != Cube[1][1][1])) {

            if (!(Cube[2][2][0] == 4 && Cube[1][2][2] == 0)) {
                F();
                U_();
                F_();
                answer.emplace_back("F U' F' ");
            } else {
                int z = 0;
                while (z < 6) {
                    F();
                    U();
                    F_();
                    U_();
                    answer.emplace_back("F U F' U' ");
                    z++;
                    if (Cube[2][2][0] == Cube[2][1][1] && Cube[1][2][2] == Cube[1][1][1] &&
                        Cube[5][0][0] == Cube[5][1][1])
                        break;
                }
/*
                    if (!(Cube[0][2][0] == Cube[0][1][1] && Cube[4][2][2] == Cube[4][1][1] &&
                          Cube[3][0][0] == Cube[3][1][1])) {
                        F();
                        _U();
                        _F();
                    //}*/

            }
        } else if (Cube[5][0][2] == Cube[5][1][1]
                   && (Cube[2][2][2] != Cube[2][1][1] || Cube[3][2][0] != Cube[3][1][1])) {
            if (!(Cube[2][2][2] == 5 && Cube[3][2][0] == 0)) {
                R();
                U_();
                R_();
                answer.emplace_back("R U' R' ");
            } else {
                int z = 0;
                while (z < 6) {
                    R();
                    U();
                    R_();
                    U_();
                    answer.emplace_back("R U R' U' ");
                    z++;
                    if (Cube[2][2][2] == Cube[2][1][1] && Cube[3][2][0] == Cube[3][1][1] &&
                        Cube[5][0][2] == Cube[5][1][1])
                        break;
                }
/*
                    if (!(Cube[0][2][2] == Cube[0][1][1] && Cube[5][2][0] == Cube[5][1][1] &&
                          Cube[3][0][2] == Cube[3][1][1])) {
                        R();
                        _U();
                        _R();
                   // }*/
            }
        } else if (Cube[5][2][2] == Cube[5][1][1]
                   && (Cube[3][2][2] != Cube[3][1][1] || Cube[4][2][0] != Cube[4][1][1])) {
            if (!(Cube[3][2][2] == 1 && Cube[4][2][0] == 5)) {
                B();
                U_();
                B_();
                answer.emplace_back("B U' B' ");
            } else {
                int z = 0;
                while (z < 6) {
                    B();
                    U();
                    B_();
                    U_();
                    z++;
                    answer.emplace_back("B U B' U' ");
                    if (Cube[3][2][2] == Cube[3][1][1] && Cube[4][2][0] == Cube[4][1][1] &&
                        Cube[5][2][2] == Cube[5][1][1])
                        break;
                }/*
                    if (!(Cube[5][2][2] == Cube[5][1][1] && Cube[1][2][0] == Cube[1][1][1] &&
                          Cube[3][2][2] == Cube[3][1][1])) {
                        B();
                        _U();
                        _B();
                    }*/
            }
        } else if (Cube[5][2][0] == Cube[5][1][1]
                   && (Cube[4][2][2] != Cube[4][1][1] || Cube[1][2][0] != Cube[1][1][1])) {

            int z = 0;
            if (!(Cube[1][2][0] == 3 && Cube[5][2][0] == 4)) {
                L();
                U_();
                L_();
                answer.emplace_back("L U' L' ");
            } else {
                while (z < 6) {
                    L();
                    U();
                    L_();
                    U_();
                    answer.emplace_back("L U L' U' ");
                    z++;
                    if (Cube[4][2][2] == Cube[4][1][1] && Cube[1][2][0] == Cube[1][1][1] &&
                        Cube[5][2][0] == Cube[5][1][1])
                        break;
                }/*
                    if (!(Cube[1][2][2] == Cube[1][1][1] && Cube[4][2][0] == Cube[4][1][1] &&
                          Cube[3][2][0] == Cube[3][1][1])) {
                        L();
                        _U();
                        _L();
                    }*/
            }
        } else {
            U();
            answer.emplace_back("U ");
            k++;
        }
    }

    if (!correct_flat(5)) {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < 150; i++) {
            int act = rand() % 12;
            switch (act) {
                case 0:
                    F();
                    answer.emplace_back("F ");
                    break;
                case 1:
                    F_();
                    answer.emplace_back("F' ");
                    break;
                case 2:
                    B();
                    answer.emplace_back("B ");
                    break;
                case 3:
                    B_();
                    answer.emplace_back("B' ");
                    break;
                case 4:
                    U();
                    answer.emplace_back("U ");
                    break;
                case 5:
                    U_();
                    answer.emplace_back("U' ");
                    break;
                case 6:
                    D();
                    answer.emplace_back("D ");
                    break;
                case 7:
                    D_();
                    answer.emplace_back("D' ");
                    break;
                case 8:
                    L();
                    answer.emplace_back("R ");
                    break;
                case 9:
                    L_();
                    answer.emplace_back("R' ");
                    break;
                case 10:
                    R();
                    answer.emplace_back("L ");
                    break;
                case 11:
                    R_();
                    answer.emplace_back("L' ");
                    break;
                default:
//                    throw runtime_error("File incorrect");
                    break;
            }
        }
        std::vector<std::string> answer1;

        first_step(answer1);
        second_step(answer1);
    }
    answer.emplace_back("\n\n");
}

bool RubiksCube::correct_flat(int flat_number) {
    bool flag = true;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (Cube[flat_number][i][j] != flat_number) flag = false;
        }
    }
    return flag;
}

void RubiksCube::God_algos() {
    B2();
    D2();
    F();
    R2();
    F();
    U2();

}




