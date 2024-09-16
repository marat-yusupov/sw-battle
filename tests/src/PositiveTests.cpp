#include <cstdlib>

#include <gtest/gtest.h>

#include "TestFixture.hpp"

namespace sw::test::positive
{
    TEST_F(TestFixture, ArcherAttackWarrior)
    {
        static const std::string TestCaseName = "archer_attack_warrior.txt";
        runTest(TestCaseName);
    }

    TEST_F(TestFixture, FullSimulation)
    {
        static const std::string TestCaseName = "full_simulation.txt";
        runTest(TestCaseName);
    }

    TEST_F(TestFixture, InteractionWithDiedUnit)
    {
        static const std::string TestCaseName = "interaction_with_died_unit.txt";
        runTest(TestCaseName);
    }

    TEST_F(TestFixture, TwoWarriorAttack)
    {
        static const std::string TestCaseName = "two_warrior_attack.txt";
        runTest(TestCaseName);
    }

    TEST_F(TestFixture, TwoWarriorMarchAndAttack)
    {
        static const std::string TestCaseName = "two_warrior_march_and_attack.txt";
        runTest(TestCaseName);
    }

    TEST_F(TestFixture, WarriorAndArcherAttack)
    {
        static const std::string TestCaseName = "warrior_and_archer_attack.txt";
        runTest(TestCaseName);
    }
}
