#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <GL/gl.h>
# include <GL/glut.h>
# include "libft/libft.h"
# include "square.h"
# include <SOIL/SOIL.h>
# include <string.h>
# include <time.h>
#include <limits.h>
#include <math.h>

# define BLACK_COLOR 0x8B5A2B
# define WHITE_COLOR 0xF5DEB3

# define	KEY_ESCAPE_MACOS 53
# define KEY_ESCAPE_LINUX 65307

# define EMPTY 0x00000
# define PAWN 0b00001
# define BISHOP 0b00010
# define ROOK 0b00011
# define QUEEN 0b00100
# define KNIGHT 0b00101
# define KING 0b00110

# define BLACK 0b01000
# define WHITE 0b10000

typedef struct s_pieces
{
	GLuint empty;

	GLuint white_rook;
	GLuint white_king;
	GLuint white_bishop;
	GLuint white_queen;
	GLuint white_knight;
	GLuint white_pawn;
	GLuint black_rook;
	GLuint black_king;
	GLuint black_bishop;
	GLuint black_queen;
	GLuint black_knight;
	GLuint black_pawn;

	GLuint white_rook_s;
	GLuint white_king_s;
	GLuint white_bishop_s;
	GLuint white_queen_s;
	GLuint white_knight_s;
	GLuint white_pawn_s;
	GLuint black_rook_s;
	GLuint black_king_s;
	GLuint black_bishop_s;
	GLuint black_queen_s;
	GLuint black_knight_s;
	GLuint black_pawn_s;
}	t_pieces;

typedef	struct s_case
{
	int startX;
	int startY;
	int endX;
	int endY;
	int status;
	GLuint	square_img;

	struct s_case *case_n;
	struct s_case *case_s;
	struct s_case *case_w;
	struct s_case *case_e;
}	t_case;

typedef struct s_game
{
	t_case       *en_passant_target;
	//ALL BOOLEAN
	int white_to_play;

	int	white_is_check;
	int black_is_check;

	int white_can_castle_queen_side;
	int white_can_castle_king_side;
	int black_can_castle_queen_side;
	int black_can_castle_king_side;

	int is_piece_selected;
}	t_game;

typedef struct s_gui
{
	GLuint    	img;
	void    	*mlx;
	void    	*win;
	char    	*addr;
	int     	line_length;
	int			bits_per_pixel;
	int     	endian;
	t_case 		*square_selected;
	t_pieces	pieces;
	t_case		*case_list;
}	t_gui;

typedef struct	s_move
{
	t_case		*start_square;
	t_case		*end_square;
	int		start_index;
	int		end_index;
	int		score;
}		t_move;


void	init(t_gui *gui);
void	init_game(void);
void	init_gui(t_gui *gui);
void	mlx_create(t_gui *gui);
void	my_mlx_pixel_put(t_gui *gui, int x, int y, int color);
void    create_board(t_gui *gui);
int 	get_square_from_xy(int x, int y);
void    case_selected(t_gui *gui, t_case *square);

void	key_hook(unsigned char key, int x, int y);
void	mouse_hook(int button, int state, int x, int y);

int		is_king_in_check(t_gui *gui, int is_white_king);
int		try_to_move(t_gui *gui, t_case *start_square, t_case *end_square);
int		move_is_valid(t_gui *gui, t_case *start_square, t_case *end_square);
int		is_white_piece(t_case *square);
int		move_is_conform(t_gui *gui, t_case *start_square, t_case *end_square);
GLuint	get_pieces_image(t_gui *gui, t_case *square);
void	deselect_piece(t_gui *gui, t_case *square);
void	load_textures(t_gui *gui);
void	draw_chess_piece(GLuint texture, int x, int y, int case_size);
void	draw_transparent_square(int x, int y, int case_size);
void	print_board_in_term(t_gui *gui);
t_gui	*clone_t_gui(t_gui *gui);
void	draw_pieces_from_case_list(t_gui *gui);

int is_square_attacked(t_gui *gui, t_case *square);
void move_piece(t_gui *gui, t_case *start_square, t_case *end_square);
void random_black_move(t_gui *gui);
void	display_board(void);
int has_valid_moves(t_gui *gui, int is_white);
void process_AI(t_gui *gui);
void generate_valid_moves(t_gui *gui, int is_white, t_move *valid_moves, int *move_count);

extern t_game game;
extern t_gui *gui;

#endif