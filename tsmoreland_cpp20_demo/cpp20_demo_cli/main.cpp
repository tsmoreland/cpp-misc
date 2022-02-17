import addlib;
import subtractlib;
import multlib;
import<iostream>;

int main() {
  const int add_result = tsmoreland::math::addlib::add(1, 2);
  std::cout << "1 + 2 = " << add_result << "\n";

  const int sub_result = tsmoreland::math::subtractlib::subtract(3, 1);
  std::cout << "3 + 1 = " << sub_result << "\n";

  const int mult_result = tsmoreland::math::multlib::multiply(3, 4);
  std::cout << "3 * 4 = " << mult_result << "\n";

  return 0;
}
