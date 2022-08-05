#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <ctime>
#include "ICube.h"

class ICube{
protected:
    virtual void read(const char*) = 0;
    virtual void U() = 0; virtual void U_() = 0; virtual void U2() = 0; //
    virtual void D() = 0; virtual void D_() = 0; virtual void D2() = 0; //
    virtual void R() = 0;  virtual void R_() = 0; virtual void R2() = 0; //
    virtual void L() = 0;  virtual void L_() = 0; virtual void L2() = 0; //
    virtual void F() = 0;  virtual void F_() = 0; virtual void F2() = 0; //
    virtual void B() = 0;  virtual void B_() = 0; virtual void B2() = 0; //
    virtual void M() = 0;  virtual void M_() = 0; virtual void M2() = 0; //
    virtual void E() = 0;  virtual void E_() = 0; virtual void E2() = 0; //
    virtual void S() = 0;  virtual void S_() = 0; virtual void S2() = 0; //
};

class RubiksCube: public ICube{
public:
    RubiksCube();
    friend std::ostream& operator<<(std::ostream &out, RubiksCube &cube);
    void read(const char*) override;
    void flat_rotation(int flat_number, bool direction);
    void top_bottom_rotation(int line, bool direction);
    void right_rotation(int column);
    void left_rotation(int column);
    void face_back_rotation(int x, int bias);
    void inside_rotation(bool direction);
    void S_rotation(bool direction);
    void U() override; void U_() override; void U2() override;
    void D() override; void D_() override; void D2() override;
    void R() override; void R_() override; void R2() override;
    void L() override; void L_() override; void L2() override;
    void F() override; void F_() override; void F2() override;
    void B() override; void B_() override; void B2() override;
    void M() override; void M_() override; void M2() override;
    void E() override; void E_() override; void E2() override;
    void S() override; void S_() override; void S2() override;
    void first_step(std::vector<std::string> &answer);
    void second_step(std::vector<std::string> &answer);
    bool correct_flat(int flat_number);
    void God_algos();
private:
    int Cube[6][3][3]{};
    int Correct_Cube[6][3][3] = {
            { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
            { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } },
            { { 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 } },
            { { 3, 3, 3 }, { 3, 3, 3 }, { 3, 3, 3 } },
            { { 4, 4, 4 }, { 4, 4, 4 }, { 4, 4, 4 } },
            { { 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 } }
    };
};



