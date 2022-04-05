
## Warning 

The sharing of this project on my GitHub aims to help peoples to open their minds to new logics or help peoples in case of difficulty. In no way, that aims to copy and paste this work on your own repository.

# cub3d [![mamaurai's 42 cub3d Score](https://badge42.vercel.app/api/v2/cl1l4qz93000609l4yixitcl4/project/2515274)](https://github.com/JaeSeoKim/badge42)

**cub3d** is a project from the **42** Common Core, The project aims to recreate the graphic engine used in Wolfenstein 3D. If you want to learn more about Recasting you can easily find resources and videos who explains "What recasting is ?"

### Usage

	~/> git clone --recurse-submodules https://github.com/mathias-mrsn/cub3d
	~/> cd cub3d
	~/cub3d$> make
	~/cub3d$> ./cub3d maps/mandatory/map.cub 
## bonus

The cub3d bonus part contains 6 bonuses :
-	animated sprites.
-	automatic doors opening.
-	camera control with mouse.
-	wall collision.
-	modular resolution variables
-	gun
-	minimap

### Usage

	~/cub3d$> make bonus
	~/cub3d$> ./cub3d maps/bonus/map.cub

## Work Plan

Here is a little work plan to easily start this project

-	[x] Find resources about how raycasting works (3 days)
-	[x] Create parser + test it to be sure that everything right (5 days)
-	[x] Launch rays and compute distance for each ray (7 days)
-	[x] Display your first result without texture (2 days)
-	[x] Display textures (2 days)
-	[x] Manage mouvements and wall collision (1 days)
-	[x] Do more test (corner collision, parsing error...)
-	[x] Check leaks
-	[x] Norme
-	[x] Do more test (again...)

## screeshot

![cub3d](screenshots/screenshot.png?raw=true "cub3d")

![cub3d](screenshots/screenshot_2.png?raw=true "cub3d")


