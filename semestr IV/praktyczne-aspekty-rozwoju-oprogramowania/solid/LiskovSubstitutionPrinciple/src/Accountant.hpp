#pragma once
struct Accountant
{
    Accountant(std::vector<std::unique_ptr<Employee>> employees):employees(std::move(employees))
    {}

    void paySalaries(int budget)
    {
        if(budget > getRegularPayout())
            divideOverflow(budget-getRegularPayout());

        for(auto& e: employees)
        {
            budget -= e->getSalary();
            std::cout << "paid " << e->getSalary() << " to employee. " << budget << "$ left" << std::endl;
        }
        if (budget > 0)
        {
            std::cout << "WARNING: do something with the overflow, or the taxes will rise." << std::endl;
        }
        std::cout << std::endl;
    }
private:
    int getRegularPayout()
    {
        unsigned regularPayout = 0;
        for(auto& e: employees)
        {
            regularPayout += e->getSalary();
        }
        return regularPayout;
    }

    void divideOverflow(int overflow)
    {
        int raiseAmount = overflow / employees.size();
        for(auto& e: employees)
        {
            e->raise(raiseAmount);
        }
    }

    std::vector<std::unique_ptr<Employee>> employees;
};
