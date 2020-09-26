#ifndef PRIMERAENTREGA_LOG_H
#define PRIMERAENTREGA_LOG_H

#include <string>

extern void setNombreLog();
extern std::string getNombreLog();
extern bool setTipoLog(int tipo);
extern int getTipoLog();
extern void setNombreLogAux();
extern std::string getNombreLogAux();
extern bool logExiste(std::string ruta);

extern bool loguearInfo(std::string msj_info);
extern bool loguearDebug(std::string msj_debug);
extern bool loguearError(std::string msj_error);
extern bool loguear(std::string msj, int tipo);

#endif //PRIMERAENTREGA_LOG_H
