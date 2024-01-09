#include helper.h

void write_to_csv(std::vector<unsigned int> &global_cases, std::string filename = "./global_cases.csv")
{
    /*
     * Generates a csv (comma separated values) of (country, cases).
     * This creates a file "global_cases.csv" by default in the
     * current folder. We use the <fstream> header for writing to the
     * file.
     */

    // open file stream for output
    std::ofstream csv_file(filename);

    // csv column headers
    csv_file << "country,cases\n";

    for (size_t i = 0; i < global_cases.size(); i++)
    {

        /* We can write to a file in the same way as we write to std::cout.
         * This is because both are implemented as "streams"
         *
         * We do not need to pass the "countries" array to our
         * "function" since it is global. Avoid doing this,
         * we will learn better ways to organize our code later.
         */
        csv_file << countries[i] << "," << global_cases[i] << "\n";
    }

    csv_file.close();
}

void populate_vector(std::vector<unsigned int> &global_cases)
{
    /*
     * Populate a vector with pseudo-random data generated using the mersenne
     * twister engine from <random>. The seed is set to 0 so that everyone
     * gets the same sequence of 'random' numbers.
     */

    auto seed = 0;
    auto min = 0;
    auto max = 10000;

    // mt19337: a pseudo random generator using the mersenne
    // twister engine ( from <random> )
    // The value of gen will be updated every time we access it.
    std::mt19937 gen(seed);
    // uniform_int_distribution: use the mersenne twister
    // engine to generate a uniform random distribution over (min, max)
    std::uniform_int_distribution<unsigned int> unif_distrib(min, max);

    /* 3. populate vector global_cases with random data
     * You can generate samples from the uniform distribution above like so:
     * unif_distrib(gen)
     */

    // 3. solution
    for (auto &elem : global_cases)
    {
        elem = unif_distrib(gen);
    }
}

std::ostream &operator<<(std::ostream &os, std::vector<unsigned> vec)
{
    for (const auto &elem : vec)
    {
        os << elem << " ";
    }
    os << '\n';
    return os;
}

std::ostream &operator<<(std::ostream &os, std::vector<double> vec)
{
    for (const auto &elem : vec)
    {
        os << elem << " ";
    }
    os << '\n';
    return os;
}

struct DataFrame
{
    std::vector<std::string> regions;
    std::vector<unsigned> population;
    // cases[i] is a vector containing
    // daily cases observed in regions[i]
    // for multiple days.
    std::vector<std::vector<unsigned>> cases;
};

std::unique_ptr<DataFrame> read_from_csv(std::string filename)
{
    /*
    ** Read from a csv and populate a DataFrame.
    ** Return a unique_ptr to this DataFrame.
    */

    std::ifstream database(filename);

    std::unique_ptr<DataFrame> data = std::make_unique<DataFrame>();

    // parse data into these vars
    unsigned day_of_month;
    unsigned cases;
    std::string region;
    unsigned population;
    std::string curr_region = "";

    std::string line;
    // throw away first line: contains csv header
    std::getline(database, line);

    // keep track of region number
    // region names are repeated in csv
    auto region_num = -1;

    // while lines in csv
    while (std::getline(database, line))
    {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream line_stream(line);
        // stringstream breaks on spaces
        line_stream >> day_of_month >> cases >> region >> population;

        if (curr_region != region)
        {
            // -> operator: dereference pointer + access member / field
            // e.g. imagine: DataFrame* data;
            // then to access the cases field
            // we need: (*data).cases == data->cases
            curr_region = region;
            data->regions.push_back(region);
            data->population.push_back(population);
            data->cases.push_back(std::vector<unsigned>{});

            ++region_num;
        }

        data->cases[region_num].push_back(cases);
    }
    return data;
}

std::map<std::string, std::vector<double>> normalize_per_capita(std::unique_ptr<DataFrame> &data_frame)
{
    /*
    ** Normalize cases in data_frame by population i.e.
    ** compute cases per 100,000 people in each country.
    ** Returns a std::map<std::string, std::vector<double>>
    */

    auto &cases = data_frame->cases;
    auto &regions = data_frame->regions;
    auto &population = data_frame->population;

    // map: name of region to a vector containing cases
    std::map<std::string, std::vector<double>> cases_normalized;

    for (size_t region_num = 0; region_num < regions.size(); ++region_num)
    {
        auto reg_name = regions[region_num];
        auto reg_pop = population[region_num];

        // for each region, go over its cases
        for (size_t day_num = 0; day_num < cases[region_num].size(); ++day_num)
        {
            auto daily_normalized = (100'000.0 * cases[region_num][day_num]) / reg_pop;
            // populate map
            cases_normalized[reg_name].push_back(daily_normalized);
        }
    }
    return cases_normalized;
}