/*Вам необходимо разработать для некоторой MMORPG систему
усиления игровых персонажей с помощью случайных элементов
экипировки.
Каждый персонаж может иметь некоторое количество ячеек для
установки усиления (очень часто под ячейками имеют в виду слоты для
элементов одежды, например, шлем, наплечники, перчатки, плащ и др.).
Для каждого персонажа определены главные его характеристики:
здоровье, броня и, в зависимости от класса персонажа: сила, ум,
ловкость, и вторичные характеристики: меткость, везение, мастерство.
Персонажи классифицируются следующим образом: защитники,
целители, бойцы ближнего боя и бойцы дальнего боя. В зависимости от
класса персонажа для него имеет значение та или иная главная
характеристика. Для защитников – это здоровье, для целителей – ум, для
бойцов ближнего боя – ловкость или сила, для бойцов дальнего боя – ум.
Вторичные характеристики действуют одинаково для всех классов:
меткость определяет возможность промаха при атаке, везение
определяет возможность нанесения двойного урона, мастерство
увеличивает наносимый урон.
Придумайте и реализуйте закон для расчета урона (или лечения),
наносимого персонажем в зависимости от его главных и вторичных
характеристик.
Продумайте и реализуйте для каждого класса персонажа его
способности, а также систему генерации усилений. При создании
персонажа никаких усилений (экипировки) у него нет. Продумайте
возможность генерации необходимых элементов. Обратите внимание
что на каждом предмете экипировки могут быть следующие
характеристики: здоровье, броня, ум или сила, или ловкость, и одна или
две вторичные характеристики.
5
Общая характеристика персонажа определяется как суммарная
совокупность значений характеристик на всех его элементах
экипировки.
Разрабатывая данную систему вам необходимо использовать
стандартный функционал STL. При демонстрации программы вам
необходимо показать генерацию элементов экипировки созданного
персонажа, наносимый урон способностями в зависимости от текущих
характеристик. Так же необходимо иметь возможность создать
произвольное количество случайных персонажей (со случайной
экипировкой).*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

class Character {
private:
    int health;         // здоровье  do 100
    int armor;          // броня     do 10
    int strength;       // сила      do 10
    int intelligence;   // ум        do 10
    int agility;        // ловкость  do 10
    int accuracy;       // меткость  do 100
    int luck;           // везение   do 100
    int mastery;    // мастерство    do 100

public:
    Character(int h, int a, int s, int i, int ag, int ac, int l, int m) {
        health = h;
        armor = a;
        strength = s;
        intelligence = i;
        agility = ag;
        accuracy = ac;
        luck = l;
        mastery = m;
    }

    // методы для получения значений характеристик
    int getHealth() { return health; }
    int getArmor() { return armor; }
    int getStrength() { return strength; }
    int getIntelligence() { return intelligence; }
    int getAgility() { return agility; }
    int getAccuracy() { return accuracy; }
    int getLuck() { return luck; }
    int getMastery() { return mastery; }

    // методы для изменения значений характеристик
    void changeHealth(int h) { health += h; }
    void changeArmor(int a) { armor += a; }
    void changeStrength(int s) { strength += s; }
    void changeIntelligence(int i) { intelligence += i; }
    void changeAgility(int ag) { agility += ag; }
    void changeAccuracy(int ac) { accuracy += ac; }
    void changeLuck(int l) { luck += l; }
    void changeProficiency(int p) { mastery += p; }

    // методы для расчета урона и лечения
    int calculateDamage() {
        // расчет урона на основе значений характеристик
        int damage = strength * mastery;
        if (rand() % accuracy + 1 >= 50) {
            damage *= 2;
        }
        return damage;
    }

    void heal(int amount) {
        // лечение на основе значений характеристик
        int healed = intelligence * mastery;
        if (accuracy >= 50 && luck >= 50) {
            healed *= 2;
        }
        else if (accuracy < 50 && luck < 50) {
            healed /= 2;
        }
        changeHealth(amount + healed);
    }
};

int main()
{
    int accuracy = 70;
    int damage = 10;

    Character player(100, 50, 10, 20, 30, 40, 50, 60);;;
    cout << player.getHealth() << endl;
    cout << player.calculateDamage() << endl;

    if ((rand() % 100 + 1) < accuracy) {
        damage *= 2;
    }
    else {
        damage = damage;
    }
    cout << damage << endl << accuracy << endl;
    return 0;
}