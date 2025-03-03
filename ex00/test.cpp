#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    try
    {
    char *s = 0;
    std::string str(s);
    std::cout << str <<  '\n';
    std::cout << str.at(5) <<  '\n';
    std::cout << str.at(42) <<  '\n';
    }
        catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "vamonos de rave" << '\n';

        std::cerr << e.what() << '\n';

    }
        catch (const std::out_of_range& e)
    {
        std::cerr << "que guapos los pelirrojos" << '\n';

        std::cerr << e.what() << '\n';

    }
    catch (const std::logic_error& e)
    {
        std::cerr << "mira parse es esta" << '\n';

        std::cerr << e.what() << '\n';

    }

    

    return 0;
}
