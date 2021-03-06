#include "mino.h"

/*
 * date: 2022/01/20
 * what: constructor
 */
tetris::
Mino::Mino()
{
  mino_initializer();
}

/*
 * date: 2022/01/20
 * what: create mino pattern
 */
void tetris::
Mino::mino_initializer()
{
  mino_initialize_I();
  mino_initialize_O();
  mino_initialize_S();
  mino_initialize_Z();
  mino_initialize_J();
  mino_initialize_L();
  mino_initialize_T();
}

/*
 * date: 2022/01/20
 * what: push I matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_I()
{
  mino_array_.push_back({
      4, 4, {
      {0, 0, 0, 0},
      {1, 1, 1, 1},
      {0, 0, 0, 0},
      {0, 0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: push O matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_O()
{
  mino_array_.push_back({
      2, 2, {
      {1, 1},
      {1, 1}}});
}

/*
 * date: 2022/01/20
 * what: push S matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_S()
{
  mino_array_.push_back({
      3, 3, {
      {0, 1, 1},
      {1, 1, 0},
      {0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: push Z matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_Z()
{
  mino_array_.push_back({
      3, 3, {
      {1, 1, 0},
      {0, 1, 1},
      {0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: push J matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_J()
{
  mino_array_.push_back({
      3, 3, {
      {1, 1, 1},
      {0, 0, 1},
      {0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: push L matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_L()
{
  mino_array_.push_back({
      3, 3, {
      {1, 1, 1},
      {1, 0, 0},
      {0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: push T matrix to mino_array_
 */
void tetris::
Mino::mino_initialize_T()
{
  mino_array_.push_back({
      3, 3, {
      {1, 1, 1},
      {0, 1, 0},
      {0, 0, 0}}});
}

/*
 * date: 2022/01/20
 * what: getter for number of types mino
 */
int tetris::
Mino::get_number_of_types_mino()
{
  return NUMBER_OF_TYPES_MINO_;
}

/*
 * date: 2022/01/20
 * what: getter for particular mino
 */
tetris::Mino::MinoStatus
tetris::Mino::get_mino_status(const int &mino_type)
{
  return mino_array_.at(mino_type);
}

/*
 * data: 2022/01/18
 * what: look at function name
 * logic:
 * [x']   [cost -sint][x]
 * [  ] = [          ][ ]
 * [y']   [sint  cost][y]
 */
void tetris::
Mino::rotation_mino(const int &mino_type, const int &rot_direction)
{
  std::vector<std::vector<int> > result_vec;
  int rot_times = (rot_direction == LEFT_ROT_ ? 1 : 3);
  int height    = mino_array_.at(mino_type).height_;
  int width     = mino_array_.at(mino_type).width_;

  result_vec.resize(height);
  for (int i = 0; i < height; ++i)
    result_vec.at(i).resize(width);

  for (int times = 0; times < rot_times; ++times) {
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        result_vec.at(i).at(j) =
          mino_array_.at(mino_type).mino_matrix_.at(j).at(height - 1 - i);
      }
    }
    mino_array_.at(mino_type).mino_matrix_ = result_vec;
  }
}
