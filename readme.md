# Recipe Collection

## Task Specifications

See all [Task Specifications](./task_specification.md)

## Compilation

To build and run the recipe collection, execute `sh ./build.sh` or alternatively run:<br><br>
>gcc enums/menu.h structs/terminal.h structs/ingredient.h structs/recipe.h globals/menu_choices.h globals/recipe.h globals/recipe_names.h globals/recipe_states.h globals/recipes_count.h globals/terminal.h globals/window.h helpers/all.h helpers/store_recipe.c helpers/clear_recipes.c helpers/get_recipes_count.c helpers/mk_file.c helpers/new_ingredient.c helpers/new_recipe.c helpers/delete_recipe.c helpers/edit_recipe.c helpers/load_recipes.c helpers/finish_recipe.c helpers/get_terminal_size.c helpers/init_recipe.c helpers/quit.c helpers/read_recipe_ingredient.c helpers/read_recipe_instruction.c helpers/read_recipe_name.c helpers/reset_box.c ncurses/all.h ncurses/show_help_with_ncurses.c ncurses/show_main_menu_with_ncurses.c ncurses/show_search_by_recipe_name_with_ncurses.c ncurses/show_search_by_ingredient_with_ncurses.c ncurses/show_selectable_menu_with_ncurses.c ncurses/show_single_recipe_with_ncurses.c main.c -std=c99 -lncurses -Wall -Wextra -pedantic -Wno-unused-parameter

To compile it, you need the GNU compiler.

Additionally you need ncurses. An installation link can be found [here](https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/).

Local header files:<br><br>
`enums/menu.h`<br>
<br>
`globals/menu_choices.h`<br>
`globals/recipe.h`<br>
`globals/recipe_names.h`<br>
`globals/states.h`<br>
`globals/recipes_count.h`<br>
`globals/terminal.h`<br>
`globals/window.h`<br>
<br>
`helpers/all.h`<br>
<br>
`ncurses/all.h`<br>
<br>
`structs/ingredient.h`<br>
`structs/recipe.h`<br>
`structs/terminal.h`<br>

## Execution

You can execute the recipe collection with the generated `*.out` file.<br>
e.g. `./recipe_collection.out [filename]`

The filename argument is required. If the file does not exist, the file will be created for you.

> Optional options:
> -h -> help
> -f[filename] e.g. -fdatabase.txt

After executing the program, you will see the main menu.

## Completed Tasks

1. Main Task (30 pts.)
   1. All recipes are stored in a file and read from file. The user can list and see them through the executable.
2. Task (10 pts.)
   1. Partially implemented. You can search for an ingredient.
3. Task (15 pts.)
   1. Partially implemented. You can search by an ingredient / recipe name.
4. Task (15 pts.)
   1. A user can add new recipes including new ingredients.
5. Task (15 pts.)
   1. I began to implement this function, but I had no time left.
6. Task (30 pts.)
   1. ncurses is used through the whole program.
7. Task (10 pts.)
   1. Implemented. A user can filter recipes / recipes by ingredient

getopt is implemented, too.<br>
Additionally: A user can delete a recipe.