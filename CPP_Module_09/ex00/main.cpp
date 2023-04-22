# include "BitcoinExchange.hpp"

const &std::map<string, int> parse_data_base(std::ifstream &input_data) throw(std::invalid_argument&){
  std::string Line;
  std::getLine(input_data, Line);
  if (Line != "date,exchange_rate\n")
    throw(std::invalid_argument("Error: The database is in an incorrect format\n"))
  while (std::getLine(input_data, Line)){
    if (Line){

    }
  }
}

const &std::map<string, int> initData(const int &argc, const char &*argv) throw(std::invalid_argument&, std::runtime_error&){
   if (argc == 1)
    throw std::invalid_argument( "Error: could not open file.\n");
  if (argc != 2)
   throw std::invalid_argument ("Error: argument must be only one!!\n");
  std::ifstream input_data_base("data.csv");
  if (!input_data_base.is_open())
    throw std::runtime_error("Error : there is no data\n");
}

int main(int argc, char *argv[]){
  try {
    const std::map<strig, int> &data_base = initData(argc, argv[1]);
  }
  catch(std::exception &e){
    std::cerr<< e.what();
  }
  return (0);
}
