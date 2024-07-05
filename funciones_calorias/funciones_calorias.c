# include <stdio.h>
# include "estructuras_usuario/estructuras_usuario.h"

// declarion de constantes kcal


// transforma las horas a minutos
float hour_to_min(float hora)
{
    return hora * 60;
}

float kcal(int num, float duracion)
{
    // cada numero representa una actividad
    //1 = caminar, 2 = correr, 3 = crossfit, 4 = artes_marciales, 5 = ciclismo, 6 = futbol, 7 = levantamiento_pesas
    //8 = nadar, 9 = padel, 10 = pilates, 11 = tenis, 12 = voleibol , 13 = yoga, 14 = calistenia

    switch (num)
    {
        case 1:
            return 4 * hour_to_min(duracion);
            break;
        case 2:
            return 11.7 * hour_to_min(duracion);
            break;
        case 3:
            return 13.3 * hour_to_min(duracion);
            break;
        case 4:
            return 9.8 * hour_to_min(duracion);
            break;
        case 5:
            return 11.5 * hour_to_min(duracion);
            break;
        case 6:
            return 8.5 * hour_to_min(duracion);
            break;
        case 7:
            return 10 * hour_to_min(duracion);
            break;
        case 8:
            return 9.8 * hour_to_min(duracion);
            break;
        case 9:
            return 7.8 * hour_to_min(duracion);
            break;
        case 10:
            return 4.5 * hour_to_min(duracion);
            break;
        case 11:
            return 9.19 * hour_to_min(duracion);
            break;
        case 12:
            return 5.9 * hour_to_min(duracion);
            break;
        case 13:
            return 3 * hour_to_min(duracion);
            break;
        case 14:
            return 8.3 * hour_to_min(duracion);
            break;
        default:
            return 0;
            break;
    }
}
