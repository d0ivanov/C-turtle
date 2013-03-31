#include<iostream>
#include<cstdlib>

using namespace std;

enum Direction {
	NONE = 0,
	UP=1,
	LEFT = 1<<1,
	DOWN = 1<<2,
	RIGHT = 1<<3
};

class Cell {
	unsigned char walls_;
	int row_;
	int col_;
	bool visited_;
public:
	Cell(unsigned char walls = static_cast<unsigned char>(UP|LEFT|DOWN|RIGHT))
	:	walls_(walls),
		row_(-1),
		col_(-1),
		visited_(false)
	{}

 	void clear() {
 		walls_ = static_cast<unsigned char>(UP|LEFT|DOWN|RIGHT);
 		visited_ = false;
 	}

 	bool isVisited() const {
 		return visited_;
 	}

 	Cell& setVisited() {
 		visited_ = true;
 		return *this;
 	}

  Cell& unvisit() {
    visited_ = false;
    return *this;
  }

	Cell& setWall(Direction dir) {
		walls_ = dir | walls_;
		return *this;
	}

 	Cell& unsetWall(Direction dir) {
 		walls_ = ~ dir & walls_;
 		return *this;
 	}

	bool hasWall(Direction dir) const{
		return (walls_ & dir) != 0;
	}

	Cell& setCoords(int row, int col) {
		row_ = row;
		col_ = col;
		return *this;
	}

	int getRow() const {
		return row_;
	}

	int getCol() const {
		return col_;
	}
};


class BoardError{};

class Board {
	Cell *cells_;
	int nrows_;
	int ncols_;

	bool checkBoardCoords(int row, int col) const{
		if(row >= 0 && row < nrows_ && col>=0 && col < ncols_) return true;
		return false;
	}

public:
	Board(int nrows, int ncols)
	:cells_(new Cell[nrows*ncols]),
	 nrows_(nrows),
	 ncols_(ncols)
	{
		for(int i = 0; i < nrows_; i++) {
			for(int j = 0; j < ncols_; j++) {
				getCell(i,j).setCoords(i,j);
			}
		}
	}

	~Board() {
		delete [] cells_;
	}

	Cell& getCell(int row, int col) {
		if(!checkBoardCoords(row, col)) {
			throw BoardError();
		}
		int cell_ind = row * ncols_ + col;
		return cells_[cell_ind];
	}

	const Cell& getCell(int row, int col) const {
		if(!checkBoardCoords(row, col)) {
			throw BoardError();
		}
		int cell_ind = row * ncols_ + col;
		return cells_[cell_ind];
	}

	private:
		const static Direction DIRECTIONS[];
	public:

	bool hasUnvisitedNeighbour(Cell& cell) {
		for (int i=0; i< 4; i++) {
			Direction dir = DIRECTIONS[i];
			if(hasNeighbour(cell, dir)) {
				if (!getNeighbour(cell, dir).isVisited()) {
					return true;
				}
			}
		}

		return false;
	}

	Direction getRandomUnvisitedNeighbour(Cell& cell) {
		if(!hasUnvisitedNeighbour(cell)) {
			return NONE;
		} else {
			while(true) {
				int randIndex = rand() % 4;
				Direction randDir = DIRECTIONS[randIndex];
				if (hasNeighbour(cell, randDir)) {
					if (!getNeighbour(cell, randDir).isVisited()) {
						return randDir;
					}
				}
			}
		}
	}

	Cell& drill(Cell& cell, Direction dir) {
		cell.unsetWall(dir);
		Cell& next = getNeighbour(cell, dir);

		switch(dir) {
			case UP:
				next.unsetWall(DOWN);
				break;
			case DOWN:
				next.unsetWall(UP);
				break;
			case LEFT:
				next.unsetWall(RIGHT);
				break;
			case RIGHT:
				next.unsetWall(LEFT);
				break;
			default:
				throw BoardError();
		}

		return next;
	}

	void generate(Cell& start) {
			start.setVisited();

			while (true) {
				Direction dir = getRandomUnvisitedNeighbour(start);
				if (dir == NONE) {
					return;
				}
				Cell& next = drill(start, dir);
				generate(next);
			}
	}

	bool hasNeighbour(const Cell& cell, Direction dir) const {
		if(cell.getRow() == 0 && (dir&UP)) return false;
		if(cell.getRow() == (nrows_ - 1) && (dir&DOWN)) return false;
		if(cell.getCol() == 0 && (dir&LEFT)) return false;
		if(cell.getCol() == (ncols_ - 1) && (dir&RIGHT)) return false;
		return true;
	}

	Cell& getNeighbour(const Cell& cell, Direction dir) {
		int row = cell.getRow();
		int col = cell.getCol();

		if( (dir&UP)) row -= 1;
		if((dir&DOWN)) row += 1;
		if((dir&LEFT)) col -= 1;
		if((dir&RIGHT)) col += 1;

		return getCell(row,col);
	}

	const static int DRAW_PS = 15;

	void draw_ps(ostream& out) {
		out << "newpath" << endl;

		for(int i = 0; i < nrows_; i++) {
			for(int j = 0; j < ncols_; j++) {
				Cell c = getCell(i,j);

				int x = j*DRAW_PS + 2*DRAW_PS;
				int y = (nrows_ - i)*DRAW_PS + 3*DRAW_PS;

				out << x << " " << y << " moveto" << endl;
				out << DRAW_PS << " 0 ";
				if(c.hasWall(UP)) {
					out << "rlineto" << endl;
				}else{
					out << "rmoveto" << endl;
				}

				out << "0 " << -DRAW_PS << " ";
				if(c.hasWall(RIGHT)) {
					out << "rlineto" << endl;
				}else{
					out << "rmoveto" << endl;
				}

				out << -DRAW_PS << " 0 ";
				if(c.hasWall(DOWN)) {
					out << "rlineto" << endl;
				}else{
					out << "rmoveto" << endl;
				}

				out << "0 " << DRAW_PS << " ";
				if(c.hasWall(LEFT)) {
					out << "rlineto" << endl;
				}else{
					out << "rmoveto" << endl;
				}
			}
		}
		out << "stroke" << endl;
	}

  void show_page(ostream& out) {
    out << "showpage" << endl;
  }

  void mark_ps(ostream& out, const Cell& cell) {
    int x = cell.getCol() * DRAW_PS + 2 * DRAW_PS;
    int y = cell.getRow() * DRAW_PS + 3 * DRAW_PS;

    out << x + DRAW_PS / 2 << " " << y << " moveto" << endl;
    out << 0 << " " <<  DRAW_PS << " rlineto" << endl;
    out << x  << " " << y + DRAW_PS / 2 << " moveto" << endl;
    out << DRAW_PS <<  " " << 0 << " rlineto" << endl;
    out << "stroke" << endl;
  }

private:

  void clear_visited() {
    for (int i = 0; i < nrows_; i++) {
      for (int j = 0; j < ncols_; j++){
        Cell cell = getCell(i, j);
        cell.unvisit();
      }
    }

  }

public:

  void find_path(Cell& start, Cell& end){
    clear_visited();
  }
};

const Direction Board::DIRECTIONS[] = {UP, DOWN, LEFT, RIGHT};

int main() {

	Board b(20, 38);

	Cell& start = b.getCell(0,4);
	b.generate(start);

	b.draw_ps(cout);
  b.mark_ps(cout, start);
  b.show_page(cout);

	return 0;
}
