# Recipe Collection

## Task Specification

Allow the user to manage recipes in a file.

**Main Task (30 points)**
+ Define a human- and computer-readable file format that is able to store named recipes with the required amounts of ingredients.
+ Read that file in and let the user select one of the recipes to display its instructions below a list of the respective ingredients.

**Task (10 points)**
+ The user can list all recipes requiring a specified list of ingredients.

**Task (15 points)**
+ Allow the user to specify a list of ingredients with respective amounts and show only those recipes that can be made using them,
      i.e. list all recipes that do not require other types or a higher amount of the ingredients than specified.

**Task (15 points)**
+ Adding new recipes is possible interactively within the program, which appends the new recipe to the persistent file store.

**Task (15 points)**
+ Let the user edit existing recipes within the program.

**Task (30 points)**
+ Implement a nice user interface using the `ncurses` library.
+ Let the user scroll a list of all recipes to select any of them.
+ Allow the user then to take an action on the respective recipe (e.g., edit it).

**Task (10 points)**
> Provide a way within the `ncurses` interface to apply filtering of the recipes similar to the search modes described above.

**Task (15 points)**
+ The program arguments are handled by `getopt(3)`.

## Example Execution

>./recipes database.txt<br>
database.txt contains 2 recipes:<br>
[1] Vanillekipferln<br>
[2] Death by chocolate muffins<br>
Please select the number of the recipe to display, or 'q' to quit:<br>
2<br>
==========================<br>
Death by chocolate muffins<br>
==========================<br>
Ingredients:<br>
125 g     Schokolade, zartbitter<br>
125 g     Schokolade, Vollmilch<br>
2         Eier<br>
125 g     Zucker<br>
1 Beutel  Vanillezucker<br>
50 g      Kakaopulver<br>
125 g     Mehl<br>
125 g     Butter<br>
125 g     Schlagobers<br>
Fett fuer die Form<br><br>
Instructions:<br>
Die Zartbitterschokolade mit der Butter in einem Wasserbad schmelzen<br>
und etwas abkuehlen lassen. Die Eier mit dem Zucker und dem<br>
Vanillezucker schaumig schlagen bis eine cremige Masse entsteht. Das<br>
Mehl und das Kakaopulver vermischen und abwechselnd mit der Schlagobers<br>
in die Ei-Zucker-Masse ruehren. Die Schokoladenbutter unterruehren. Die<br>
Vollmilchschokolade hacken und unter den Teig heben. Die Muffinform<br>
fetten und den Teig hinein fuellen. Der Teig reicht fuer 10 Stueck. Bei<br>
200°C 15 Minuten lang backen. In der Form ca. 30-45 Minuten auskuehlen<br>
lassen. Waehrendessen intensiv Sport betreiben, bevor dies nicht mehr<br>
moeglich ist.<br>
==========================<br>
database.txt contains 2 recipes:<br>
[1] Vanillekipferln<br>
[2] Death by chocolate muffins<br>
Please select the number of the recipe to display, or 'q' to quit:<br>
> q
