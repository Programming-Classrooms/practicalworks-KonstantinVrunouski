#include "../funcs/Funcs.hpp"


int main ()
{
    try
    {
    /* Три рыбака */
    std::set<std::string> fishAll;
    std::set<std::string> fishmanDasha;
    std::set<std::string> fishmanVanya;
    std::set<std::string> fishmanVadim;

    /* Файлы содержащие улов каждого */
    std::ifstream fish("src/files/fish.txt");
    std::ifstream fish1("src/files/fishman1.txt");
    std::ifstream fish2("src/files/fishman2.txt");
    std::ifstream fish3("src/files/fishman3.txt");

    /* Проверка файлов  */
    checkFile(fish);
    checkFile(fish1);
    checkFile(fish2);
    checkFile(fish3);

    /* Запись улова */
    readFile(fishAll,fish);
    readFile(fishmanDasha,fish1);
    readFile(fishmanVanya,fish2);
    readFile(fishmanVadim,fish3);

    std::cout << "Все виды рыб: ";
    for(std::string elem: fishAll)
    {
        std::cout << elem << " ";
    }

    /* Демонстрация видов рыб каждого рыбака */
    printFish(fishmanDasha);
    printFish(fishmanVanya);
    printFish(fishmanVadim);

    /* Какие виды рыб есть у каждого рыбака */
    fishEveryone(fishmanDasha,fishmanVanya,fishmanVadim);

    /* Какие из видов выловид хотя бы один рыбак */
    fishInAll(fishmanDasha,fishmanVanya,fishmanVadim);

    /* Какие рыбы есть в озере, но не в улове любого из рыбаков Какие из видов выловид хотя бы один рыбак */
    uniqueFish(fishAll,fishmanDasha,fishmanVadim,fishmanVanya);

    return 0;
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
    catch(std::ios_base::failure e)
    {
        std::cout << e.what();
    }
    catch(std::runtime_error e)
    {
        std::cout << e.what();
    }
}
