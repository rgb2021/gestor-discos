#include <gtest/gtest.h>
#include "GestorDiscos.h"

TEST(GestorDiscosTest, SaludoCorrecto) {
    GestorDiscos gestor;
    EXPECT_EQ(gestor.saludar(), "Hola mundo desde gestor-discos 🚀");
}

TEST(GestorDiscosTest, SumaCorrectamente) {
    GestorDiscos gestor;
    EXPECT_EQ(gestor.sumar(2, 3), 5);
    EXPECT_EQ(gestor.sumar(-1, 1), 0);
}