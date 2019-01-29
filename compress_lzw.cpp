#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>

template <typename Iterator>
Iterator compress(const std::string &uncompressed, Iterator result) {
  int dictSize = 256;
  std::map<std::string,int> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[std::string(1, i)] = i;
  std::string w;
  for (std::string::const_iterator it = uncompressed.begin();
       it != uncompressed.end(); ++it) {
    char c = *it;
    std::string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      *result++ = dictionary[w];
      dictionary[wc] = dictSize++;
      w = std::string(1, c);
    }
  }
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}
template <typename Iterator>
std::string decompress(Iterator begin, Iterator end) {
  int dictSize = 256;
  std::map<int,std::string> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[i] = std::string(1, i);
 
  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ;begin!=end;begin++){
    int k = *begin;
    if (dictionary.count(k))
      entry = dictionary[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";
    result += entry;
    dictionary[dictSize++] = w + entry[0];
 
    w = entry;
  }
  return result;
}
 
int main(){
  std::vector<int> compressed;
  compress("TOBEORNOTTOBEORTOBEORNOT", std::back_inserter(compressed));
  copy(compressed.begin(), compressed.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;
  std::string decompressed = decompress(compressed.begin(), compressed.end());
  std::cout << decompressed << std::endl;
}