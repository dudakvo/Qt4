#include <QCoreApplication>
#include <iostream>
#include "QTimer"
#include <boost/program_options.hpp>

//void delay (int timeDelay)
//{
//    QEventLoop loop;
//    QTimer::singleShot(timeDelay, &loop, SLOT(quit()));
//    loop.exec();
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int timeDelay=0, im=0;

    boost::program_options::options_description optionDescription("Allowedoptions");
    optionDescription.add_options()
        ("help", "Produce help message")
        ("timeout", boost::program_options::value<int>(), "delay time")
        ;
    boost::program_options::variables_map vm;

    try
    {
    boost::program_options::store(boost::program_options::parse_command_line(argc,
                                                                             argv,
                                                                             optionDescription),
                                  vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << optionDescription << std::endl;
    }
    if (vm.count("timeout"))
    {
        timeDelay = vm["timeout"].as<int>();
    }
    }

    catch(std::exception& ex)
    {
         std::cout << optionDescription << std::endl;
    }

    std::cout<<"Time delay:"<<timeDelay<<std::endl;

    QTimer::singleShot(timeDelay, &a, SLOT(quit()));
    for (im=1;im>0;im++)
    {
        std::cout<<"Run program"<<std::endl;
    }
    return a.exec();
}
