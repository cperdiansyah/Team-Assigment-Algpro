cmake_minimum_required(VERSION 4.3)
project(Team_Assigment_Algpro C)

set(CMAKE_C_STANDARD 11)

#add_executable(Team_Assigment_Algpro
#        ACCA/tugas2a.c
#        ACCA/tugas2b.c
#        ACCA/tugas2c.c
#        DCCA/soal1.c
#        DCCA/soal2_fixed.c)


add_executable(TugasACCA_2A ACCA/tugas2a.c)
add_executable(TugasACCA_2B ACCA/tugas2b.c)
add_executable(TugasACCA_2C ACCA/tugas2c.c)
add_executable(TugasDCCA_1 DCCA/question_1.c)
add_executable(TugasDCCA_2 DCCA/question_2_fixed.c)



