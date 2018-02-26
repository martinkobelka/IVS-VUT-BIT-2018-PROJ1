//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include <cstdint>

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

namespace WhiteBoxTesting {
    
    using namespace ::testing;
    
    class MatrixDatabase : public Test {
        
    protected:
        
        Matrix matrix;
        
        Matrix ReturnSingleMatrix(double value) {
            Matrix matrix = Matrix();
            matrix.set(std::vector<std::vector<double>> {{value}});
            return matrix;
        }
        
        Matrix Return3X3(bool singular) {
            Matrix matrix = Matrix(3, 3);
            if(singular) {
                matrix.set(std::vector<std::vector<double>> {
                    {3.0, 3.0, 3.0},
                    {3.0, 3.0, 3.0},
                    {3.0, 3.0, 3.0}
                });
            }
            else {
                matrix.set(std::vector<std::vector<double>> {
                    {1.0, 2.0, -1.0},
                    {-2.0, 1.0, -3.0},
                    {0.0, 2.0, -1.0}
                });
            }
            return matrix;
        }
        
        Matrix Return2X2(bool singular) {
            Matrix matrix = Matrix(2, 2);
            if(singular) {
                matrix.set(std::vector<std::vector<double>> {
                    {3.0, 3.0},
                    {3.0, 3.0}
                });
            }
            else {
                matrix.set(std::vector<std::vector<double>> {
                    {1.0, 2.0},
                    {0.0, 2.0}
                });
            }
            return matrix;
        }
        
        Matrix Return4X4(bool singular) {
            Matrix matrix = Matrix(4, 4);
            if(!singular) {
                matrix.set(std::vector<std::vector<double>> {
                    {1.0, 0.0, 0.0, 0.0},
                    {0.0, 2.0, 0.0, 0.0},
                    {0.0, 0.0, 3.0, 0.0},
                    {0.0, 0.0, 0.0, 4.0},
                });
            }
            else {
                matrix.set(std::vector<std::vector<double>> {
                    {0.0, 0.0, 0.0, 0.0},
                    {0.0, 2.0, 0.0, 0.0},
                    {0.0, 2.0, 0.0, 0.0},
                    {0.0, 0.0, 0.0, 0.0},
                });
            }
                
            return matrix;
        }
        
    };
    
    class TestMatrix : public Test {
        
        
    protected:
        
        Matrix matrix;
        
        int count_of_values = 10;
        
        int test_values[10] = {
            1, 10, 10, 1000, 41, 21, 45, 789, 2, 5
        };
        
        int count_of_fail_values = 5;
        
        int test_fail_values[5] = {
            0, -1, -20, -564, -484564565
        };
    };
    
    class SingleMatrix : public Test {
        
    protected:
    
        Matrix matrix;
        Matrix test_matrix1X1;        
        Matrix test_matrix1X1false;
        Matrix test_matrix2X2;

        double insert_value = 42.42;
        double insert_value_bad = 56585.5;
        
        void SetUp() override{
            matrix = Matrix();
            test_matrix1X1 = Matrix();
            test_matrix1X1false = Matrix();
            test_matrix1X1.set(0, 0, insert_value);
            test_matrix1X1false.set(0, 0, insert_value_bad);
            
            test_matrix2X2 = Matrix(2, 2);
        }
        
    };
    
    class SolveEquations : public MatrixDatabase {
        
    protected:
        
        Matrix Return3X4() {
            return matrix = Matrix(3, 4);
        }
        
    };
    
    class MultipyOperation : public MatrixDatabase{
        
    };
    
    class AddOperation : public MatrixDatabase{
        
    };
    
    class CheckFixture : public MatrixDatabase{
        
    protected:
        int count_of_values = 10;
        
        int test_values[10] = {
            1, 10, 10, 1000, 41, 21, 45, 789, 2, 5
        };
        
    };
    
    TEST_F(TestMatrix, CreateMatrix) {
                
        // Create correct matrix
        EXPECT_NO_THROW(matrix = Matrix());
        
        for(int i = 0; i < count_of_values; i++) {
            
            for(int r = 0; r < count_of_values; r++) {
                
                EXPECT_NO_THROW(
                    matrix = Matrix(test_values[i], test_values[r])
                );
                
            }
        }
        
        // Create not correct matrix
        for(int i = 0; i < count_of_values; i++) {
            
            for(int r = 0; r < count_of_fail_values; r++) {
                
                EXPECT_ANY_THROW(
                    matrix = Matrix(test_values[i], test_fail_values[r])
                );
                
                EXPECT_ANY_THROW(
                    matrix = Matrix(test_fail_values[r], test_values[i])
                );
                
            }
        }
        
    }
    
    TEST_F(TestMatrix, CreateMatrixByVector) {
        
        // 1 x 1
        matrix = Matrix();
        
        EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{0.0}}));        
        EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {
            {0.0, 0.0}, 
            {0.0, 0.0}}
        ));
        
        matrix = Matrix(1, 1);
        
        EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{0.0}}));        
        EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {
            {456456.0, 456456.0}, 
            {0.15616565, 0.456564456}
        }));
        
        matrix = Matrix(2, 2);
        
        EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {{0.0}}));        
        EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
            {0.456456456, 897456.0}, 
            {8974556.48, 54456.456}
        }));
        
        matrix = Matrix(6, 6);
        
        EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {{0.0}}));        
        EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {
            {0.456456456, 897456.0}, 
            {8974556.48, 54456.456}
        }));
        
        EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0},
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0},
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0},
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0},
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0},
            {3.4, 456.456, 456.456, 879.3, 456.45, 789.0}
        }));
        
    }
    
    TEST_F(SingleMatrix, Matrix1X1) {
        
        ASSERT_TRUE(matrix.set(0, 0, insert_value));
        ASSERT_FALSE(matrix.set(1, 1, 0.0));
        
        EXPECT_EQ(matrix.get(0, 0), insert_value);
        EXPECT_TRUE(std::isnan(matrix.get(1, 1)));
        
        EXPECT_TRUE(matrix == test_matrix1X1);
        
        EXPECT_FALSE(matrix == test_matrix1X1false);
        
        ASSERT_ANY_THROW(matrix == test_matrix2X2);
        
    }
    
    
    TEST_F(SolveEquations, Matrix1X1) {
        
        const int correct_value = 40.0;
        const int fail_value = 0;
        const int left_value = 80.0;
        std::vector<double> expected_results = {
            {2.0}
        };
        
        std::vector<double> left = {
            {left_value}
        };
        std::vector<double> fail_left = {
            {left_value, },
            {left_value}
        };
        
        std::vector<double> results;
        
        // Correctm calculation
        Matrix matrix = ReturnSingleMatrix(correct_value);
        
        EXPECT_NO_THROW(results = matrix.solveEquation(left));
        
        EXPECT_EQ(expected_results, results);
                
        // uncorrect calculation
        matrix = ReturnSingleMatrix(fail_value);
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(left));
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(fail_left));
        
    }
    
    
    
    TEST_F(SolveEquations, Matrix2X2) {
        
        // Uncorrect calculation
        std::vector<double> left = {
            {5.0},
            {6.0}
        }; 
        
        Matrix matrix = Return2X2(true);
        
        std::vector<double> results;
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(left));
        
       // Correct calculation
        std::vector<double> expected_results = {
            {-1.0},
            {3.0}
        };
        
        matrix = Return2X2(false);
        EXPECT_NO_THROW(results = matrix.solveEquation(left));
        
        EXPECT_EQ(expected_results, results);
        
        
    }
    
    TEST_F(SolveEquations, Matrix3X3) {
        
        // Uncorrect calculation
        std::vector<double> left = {
            {1.0},
            {2.0},
            {-2.0}
        }; 
        
        Matrix matrix = Return3X3(true);
        
        std::vector<double> results;
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(left));
        
       // Correct calculation
        std::vector<double> expected_results = {
            {3.0},
            {-14.0/5},
            {-18.0/5}
        };
        
        matrix = Return3X3(false);
        EXPECT_NO_THROW(results = matrix.solveEquation(left));
        
        EXPECT_EQ(expected_results, results);
        
    }
     
     TEST_F(SolveEquations, Matrix4X4) {
        
        // Uncorrect calculation
        std::vector<double> left = {
            {1.0},
            {2.0},
            {3.0},
            {4.0},
        }; 
        
        Matrix matrix = Return4X4(true);
        
        std::vector<double> results;
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(left));
        
       // Correct calculation
        std::vector<double> expected_results = {
            {1.0},
            {1.0},
            {1.0},
            {1.0}
        };
        
        matrix = Return4X4(false);
        EXPECT_NO_THROW(results = matrix.solveEquation(left));
        
        EXPECT_EQ(expected_results, results);
        
    }
    
    TEST_F(SolveEquations, Matrix3X4) {
        
        // Uncorrect calculation
        std::vector<double> left = {
            {1.0},
            {2.0},
            {-2.0},
            {2.2}
        }; 
        
        Matrix matrix = Return3X4();
        
        std::vector<double> results;
        
        EXPECT_ANY_THROW(results = matrix.solveEquation(left));
        
    }
    
    TEST_F(MultipyOperation, Matrix1X1) {
        
        const double value = 13.3;
        
        Matrix matrix = ReturnSingleMatrix(value);
        
        ASSERT_NO_THROW(matrix = matrix * matrix);

        double result = matrix.get(0, 0);
        
        ASSERT_EQ(value * value, result);
        
        
    }
    
    TEST_F(MultipyOperation, Matrix3X3) {
        
        const double value = 13.3;
        
        Matrix matrix = Return3X3(true);
        
        ASSERT_NO_THROW(matrix = matrix * matrix);
        
        for(int i = 0; i < 3; i++) {
            for(int r = 0; r < 3; r++) {
                ASSERT_EQ(27, matrix.get(i, r));
            }
        }        
    }
    
    TEST_F(MultipyOperation, FailMultiply) {
        
        const double value = 13.3;
        
        Matrix single_matrix = ReturnSingleMatrix(INT32_MAX);
        
        Matrix matrix = Return3X3(true);
        
        ASSERT_ANY_THROW(single_matrix = single_matrix * matrix);
        
    }
    
    TEST_F(MultipyOperation, Matrix1X1ConstValue) {
        
        const double value = 13.3;
        
        Matrix matrix = ReturnSingleMatrix(value);
        
        ASSERT_NO_THROW(matrix = matrix * value);

        double result = matrix.get(0, 0);
        
        ASSERT_EQ(value * value, result);
        
        
    }
    
    TEST_F(MultipyOperation, Matrix3X3ConstValue) {
        
        const double value = 13.3;
        
        Matrix matrix = Return3X3(true);
        
        ASSERT_NO_THROW(matrix = matrix * value);
        
        for(int i = 0; i < 3; i++) {
            for(int r = 0; r < 3; r++) {
                ASSERT_EQ(value * 3, matrix.get(i, r));
            }
        }        
    }
    
    TEST_F(AddOperation, Matrix1X1) {
        
        const double value = 13.3;
        
        Matrix matrix = ReturnSingleMatrix(value);
        
        ASSERT_NO_THROW(matrix = matrix + matrix);
        
        ASSERT_EQ(value + value, matrix.get(0, 0));     
    }
    
    
    TEST_F(AddOperation, Matrix3X3) {
        
        const double value = 6;
        
        Matrix matrix = Return3X3(true);
        
        ASSERT_NO_THROW(matrix = matrix + matrix);
        
        for(int i = 0; i < 3; i++) {
            for(int r = 0; r < 3; r++) {
                ASSERT_EQ(value, matrix.get(i, r));
            }
        }        
    }
    
    TEST_F(AddOperation, Matrix3X3_add_1X1) {
        
        const double value = 6;
        
        Matrix matrix = ReturnSingleMatrix(value);
        
        Matrix matrix_single = Return3X3(true);
        
        ASSERT_ANY_THROW(matrix = matrix + matrix_single); 
    }
    
    
}

/*** Konec souboru white_box_tests.cpp ***/
