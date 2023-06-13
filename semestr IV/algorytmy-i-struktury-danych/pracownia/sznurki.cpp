#include <iostream>
#include <vector>
#include <algorithm>

int count_bits(unsigned long long int number){

    return __builtin_popcountll(number);

}

int main()
{
    std :: vector<std :: pair<unsigned long long int,unsigned long long int> > strings;

    int data;

    scanf ("%d", &data);

    for (int i = 0; i < data; i++){

        unsigned long long int temp_first,temp_second;
        scanf ("%llu %llu", &temp_first, &temp_second);
        std :: pair<unsigned long long int,unsigned long long int> string{temp_first, temp_second};

        strings.push_back(string);

    }

    unsigned long long int length;
    unsigned long long int count;
    std :: vector <std :: pair<unsigned long long int,unsigned long long int> > lowest_strings;

    for (std :: pair<unsigned long long int,unsigned long long int> element : strings){

        length = element.first;
        count = element.second;

        while ((length & 1) != 1){
            count = count << 1;
            length = length >> 1;
        }

        std :: pair<unsigned long long int,unsigned long long int> lowest_element {length, count};

        lowest_strings.push_back(lowest_element);

    }

    sort( lowest_strings.begin(), lowest_strings.end() );

    unsigned long long int limit = lowest_strings.size();
    unsigned long long int result = 0;

    std :: pair<unsigned long long int,unsigned long long int> temp_element = lowest_strings[0];

    for (unsigned long long int i = 1; i < limit; i++){

        if (temp_element.first == lowest_strings[i].first)
            temp_element.second += lowest_strings[i].second;

        else{
            result += count_bits(temp_element.second);
            temp_element.second =  lowest_strings[i].second;
            temp_element.first = lowest_strings[i].first;
        }
    }

    result += count_bits(temp_element.second);

    printf("%llu", result);

    return 0;
}