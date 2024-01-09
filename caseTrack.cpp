#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include "helper.h"

int main()
{

  // populate vector from worksheet 2
  std::vector<unsigned int> global_cases(num_countries, 0);
  populate_vector(global_cases);

  std::cout << "**********Choose**********\n"
            << "Press (d) for dummy data\n"
            << "Press (r) for real data" << std::endl;
  char choice;
  std::cin >> choice;

  std::unique_ptr<DataFrame> data_frame;
  if (choice == 'd')
  {
    // create DataFrame members for dummy data
    std::vector<std::vector<unsigned>> dummy_cases;
    std::vector<unsigned> dummy_population;

    for (size_t country_num = 0; country_num < countries.size(); ++country_num)
    {
      // reuse global_cases -
      dummy_cases.push_back(std::vector<unsigned>{global_cases[country_num]});
      dummy_population.push_back(1);
    }

    data_frame = std::make_unique<DataFrame>();
    // equivalent sytax for accessing member of a struct
    // through a pointer:
    (*data_frame).cases = dummy_cases;
    data_frame->population = dummy_population;
    data_frame->regions = countries;
  }
  else if (choice == 'r')
  {
    data_frame = read_from_csv();
  }
  else
  {
    std::cout << "It's fine if you cannot make up your mind. Maybe another time then...\n";
    std::exit(EXIT_FAILURE);
  }

  auto max_regions = data_frame->regions.size();
  for (size_t region_num = 0; region_num < max_regions; ++region_num)
  {
    std::cout << data_frame->regions[region_num] << ": " << data_frame->cases[region_num] << std::endl;
  }

  auto norm_map = normalize_per_capita(data_frame);

  std::cout << "Cases per 100'000 people:" << std::endl;
  for (const auto &[country, cases_normalized] : norm_map)
  {
    std::cout << country << " " << cases_normalized;
  }
}
