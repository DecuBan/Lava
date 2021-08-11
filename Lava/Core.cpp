#include "Application.hpp"
#include "Logger.hpp"

int main()
{
    Lava::Logger::Init();

    Lava::Application app;

    try
    {
        app.Run();
    }
    catch (const std::exception &exception)
    {
        LAVA_CRITICAL(exception.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}