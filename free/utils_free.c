#include "../cub3D.h"

void    free_tab(t_scene *scene)
{
    int i;

    i = 0;
    while (scene->asset.tab_path[i])
    {
        free(scene->asset.tab_path[i]);
        i++;
    }
    i = 0;
    while (scene->asset.asset_color[i])
    {
        free(scene->asset.asset_color[i]);
        i++;
    }
    free(scene->asset.asset_color);
    free(scene->asset.tab_path);
    free(scene->asset.floor_color);
    free(scene->asset.asset_NSWE);
}

void    tab_free(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str != NULL)
            free(str);
        i++;
    }
}