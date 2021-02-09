/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio programado en C++ y creado con propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#include "LC_Utils.h";

using namespace LC_Utils;
using namespace std;

/// <summary>
/// Lee el archivo XML para interpretarlo con la libreria RapidXML
/// </summary>
void Serialization::read_xml()
{
    N_DEBUG_WARNING(resource);

    std::string xml_file_contents;
    std::ifstream file(resource, std::ifstream::binary);

    if (file)
    {
        // Obtengo la longitud de la cadena
        file.seekg(0, ifstream::end);

        if (file.good())
        {
            auto length = file.tellg();

            if (length > 0)
            {
                file.seekg(0, ifstream::beg);

                xml_file_contents.resize(length);

                if (file.good())
                {
                    DEBUG_LOG("Leyendo ");
                    DEBUG_LOG(length);
                    N_DEBUG_LOG(" caracteres");

                    // Leo el bloque de cadena
                    file.read(&xml_file_contents.front(), length);

                    if (file.good())
                    {
                        // Se parsea el contenido del archivo XML
                        rapidxml::xml_document< > document;

                        document.parse< 0 >(const_cast<char*>(xml_file_contents.c_str()));

                        // Se obtiene el tag raiz
                        xml_node < >* scene_node = document.first_node();

                        if (scene_node)
                        {
                            //return parse_scene(scene_node);
                        }

                        file.close();

                        DEBUG_LOG("Se ha leido correctamente el archivo: ");
                        N_DEBUG_LOG(file_name);
                    }
                    else
                    {
                        N_DEBUG_ERROR("No se ha podido leer el archivo");
                    }
                }
            }
        }
    }
}


/// <summary>
/// Parsea la información del XML (TODO)
/// </summary>
/// <param name="scene_node"> nodo correspondiente a su etiqueta </param>
/// <returns> bool </returns>
bool Serialization::parse_scene(xml_node<>* scene_node)
{
    if (std::string(scene_node->name()) != "scene") return false;

    // TODO: Se crea el objeto correspondiente

    for (auto child = scene_node->first_node(); child; child = child->next_sibling())
    {
        // TODO: Se parsea la siguiente etiqueta pasandole el objeto creado
        //funcionquesea(child, object)
    }

    // TODO: Se asigna el objeto 
    return true;
}