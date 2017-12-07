# include <iostream>
#include<fstream>
# include <tpl_graph.H>		//incluye el tipo de dato List_Digraph
#include<tpl_graph_utils.H>	//incluye la clase Distance
#include<string>
#include <Dijkstra.H>		//very obvious
#include<generate_graph.H>
#include<Tarjan.H>
#include<map>

using namespace std;

// Alias para el tipo de nodo y arco.
using Node = Graph_Node<string>;
using Arc = Graph_Arc<float>;


// Alias para el tipo de grafo
using GT = List_Digraph<Node,Arc>;



void print_graph(GT & g)
{
  // Imprime la cantidad de nodos del grafo
  cout << g.get_num_nodes() << " nodes\n";

  // Itera sobre el conjunto completo de nodos
  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto p = it.get_curr();

      // Imprime la cantidad de arcos adyacentes a p
      cout << "Node " << p->get_info() << ", "
	   << g.get_num_arcs(p) << " adjacent arcs: ";

      // Para el nodo que está visitando, itera sobre todos sus arcos adyacentes.
      for (GT::Node_Arc_Iterator ait(p); ait.has_curr(); ait.next())
	{
	  // Obtiene el nodo adyacente a p
	  auto q = ait.get_tgt_node();
	  cout << q->get_info() << ' ';
	}

      cout << endl;
    }

 cout << endl << endl;

  // Imprime la cantidad total de arcos del grafo
  cout << g.get_num_arcs() << " arcs\n";

  // Itera sobre todos los arcos del grafo.
  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();

      auto p = g.get_src_node(a);
      auto q = g.get_tgt_node(a);

      cout << p->get_info() << " --> " << q->get_info() << " con peso --> "<< a->get_info();//here
    }
}

int main()
{
  GT graph, dijkstra_test; //por using es lo mismo que usar List_Digraph<Graph_Node<char>,GraphArc<Int>> graph;


//Ahora todos los nodos

	auto MR5A = graph.insert_node("Redoma 5 aguilas blancas");
	auto MCSF = graph.insert_node("calle San Francisco");
	auto MCSD0 = graph.insert_node("calle san diego A");
	auto MCSD1 = graph.insert_node("calle san diego B");
	auto MCSD2 = graph.insert_node("calle san diego C");
	auto MCSD3 = graph.insert_node("calle san diego D");
	auto MCET = graph.insert_node("calle estacion teleferico");
	auto MCACM = graph.insert_node("Cll la Aguada - Calle la Montaña");
	auto MCLA = graph.insert_node("Calle La Aguada");
	auto MCACP = graph.insert_node("Calle la Aguada- Calle Pico Espejo");
	auto M1 = graph.insert_node("Calle 1");
	auto M1E = graph.insert_node("Calle 1 final");
	auto M2 = graph.insert_node("Calle 2");
	auto M2E = graph.insert_node("Calle 2 final");
	auto M3 = graph.insert_node("Calle Loma Redonda Esquina Cll. La Montaña");
	auto M4 = graph.insert_node("Cll. La Montaña - Cll. Loma Redonda");
	auto M5 = graph.insert_node("Cll. Nevados - Cll. Pico Espejo");
	auto M6 = graph.insert_node("Cll. 3 - Cll. Hoyada de Milla");
	auto M7 = graph.insert_node("Cll 3 Interseccion");
	auto M8 = graph.insert_node("Cll. 3 Final");
	auto M9 = graph.insert_node("Cll. 4 - Cll. 5");
	auto M9a = graph.insert_node("Cll. 4 - Cll. 5 - 2");
	auto M10 = graph.insert_node("Calle 4");
	auto M11 = graph.insert_node("Calle 4 - Hoyada de Milla");
	auto M12 = graph.insert_node("Calle 5 - Hoyada de Milla");
	auto M13 = graph.insert_node("Calle 6 - Hoyada de Milla");
	auto M14 = graph.insert_node("Calle 7 - Hoyada de Milla");
	auto M15 = graph.insert_node("Antes de la redoma");
	auto M16 = graph.insert_node("Redoma de la avenida universidad");
	auto M17 = graph.insert_node("Calle 7 - Avenida Universidad");
	auto M18 = graph.insert_node("Calle 6 - Avenida Universidad");
	auto M19 = graph.insert_node("Interseccion Av. Universidad - La Milagrosa");
	auto M20 = graph.insert_node("Calle Los Nevados - Calle Yagrumo");
	auto M21 = graph.insert_node("Chorros - MIlagrosa");
	auto M22 = graph.insert_node("Enlace Charles Chaplin");
	auto M23 = graph.insert_node("Enlace German Briceño");
	auto M24 = graph.insert_node("Gran Mision Vivienda Venezuela Plaza Toros");
	auto M25 = graph.insert_node("Plaza de Toros - Avda. Las Americas");
	auto M26 = graph.insert_node("CLL 11 - AV 2");
	auto M27 = graph.insert_node("CLL 11 - AV 1");
	auto M28 = graph.insert_node("CLL 12 - AV 2");
	auto M29 = graph.insert_node("CLL 12 - AV 1");
	auto M30 = graph.insert_node("CLL 13 - AV 1");
	auto M31 = graph.insert_node("CLL 13 - AV 2");
	auto M32 = graph.insert_node("CLL 14 - AV 2");
	auto M33 = graph.insert_node("CLL 14 - AV 1");
	auto M34 = graph.insert_node("CLL 13 - AV 3");
	auto M35 = graph.insert_node("CLL 14 - AV 3");
	auto M36 = graph.insert_node("CLL 13 - AV 4");
	auto M37 = graph.insert_node("CLL 13 - AV 5");
	auto M38 = graph.insert_node("CLL 14 - AV 4");
	auto M39 = graph.insert_node("CLL 14 - AV 5");
	auto M40 = graph.insert_node("CLL 14 - AV 6");
	auto M41 = graph.insert_node("CLL 15 - AV 1");
	auto M42 = graph.insert_node("CLL 15 - AV 2");
	auto M43 = graph.insert_node("CLL 15 - AV 3");
	auto M44 = graph.insert_node("CLL 15 - AV 4");
	auto M45 = graph.insert_node("CLL 15 - AV 5");
	auto M46 = graph.insert_node("CLL 15 - AV 6");
	auto M47 = graph.insert_node("CLL 15 - AV 7");
	auto M48 = graph.insert_node("CLL 16 - AV 1");
	auto M49 = graph.insert_node("CLL 16 - AV 2");
	auto M50 = graph.insert_node("CLL 16 - AV 3");
	auto M51 = graph.insert_node("CLL 16 - AV 4");
	auto M52 = graph.insert_node("CLL 16 - AV 5");
	auto M53 = graph.insert_node("CLL 16 - AV 6");
	auto M54 = graph.insert_node("CLL 16 - AV 7");
	auto M55 = graph.insert_node("CLL 16 - AV 8");
	auto M56 = graph.insert_node("CLL 17 - AV 1");
	auto M57 = graph.insert_node("CLL 17 - AV 2");
	auto M58 = graph.insert_node("CLL 17 - AV 3");
	auto M59 = graph.insert_node("CLL 17 - AV 4");
	auto M60 = graph.insert_node("CLL 17 - AV 5");
	auto M61 = graph.insert_node("CLL X1 - AV 7");
	auto M62 = graph.insert_node("CLL X1 - AV 8");
	auto M63 = graph.insert_node("CLL 17 - AV 7");
	auto M64 = graph.insert_node("CLL 17 - AV 8");
	auto M65 = graph.insert_node("AV 8 - Pasaje Sanchez");
	auto M66 = graph.insert_node("Pasaje Sanchez - CLL X1");
	auto M67 = graph.insert_node("CLL 17 - Pasaje Sanchez");
	auto M68 = graph.insert_node("CLL 17 - AV 6");
	auto M69 = graph.insert_node("CLL Y1 - AV 8");
	auto M70 = graph.insert_node("CLL Y1 - Pasaje Sanchez");
	auto M71 = graph.insert_node("CLL 18 - AV 1");
	auto M72 = graph.insert_node("CLL 18 - AV 2");
	auto M73 = graph.insert_node("CLL 18 - AV 3");
	auto M74 = graph.insert_node("CLL 18 - AV 4");
	auto M75 = graph.insert_node("CLL 18 - AV 5");
	auto M76 = graph.insert_node("CLL 18 - AV 6");
	auto M77 = graph.insert_node("CLL 18 - AV 7");
	auto M78 = graph.insert_node("CLL 18 - AV 8");
	auto M79 = graph.insert_node("CLL 19 - AV 1");
	auto M80 = graph.insert_node("CLL 19 - AV 2");
	auto M81 = graph.insert_node("CLL 19 - AV 3");
	auto M82 = graph.insert_node("CLL 19 - AV 4");
	auto M83 = graph.insert_node("CLL 19 - AV 5");
	auto M84 = graph.insert_node("CLL 19 - AV 6");
	auto M85 = graph.insert_node("CLL 19 - AV 7");
	auto M86 = graph.insert_node("CLL 19 - AV 8");
	auto M87 = graph.insert_node("CLL 18 - Pasaje Sanchez");
	auto M88 = graph.insert_node("CLL 20 - AV 1");
	auto M89 = graph.insert_node("CLL 20 - AV 2");
	auto M90 = graph.insert_node("CLL 20 - AV 3");
	auto M91 = graph.insert_node("CLL 20 - AV 4");
	auto M92 = graph.insert_node("CLL 20 - AV 5");
	auto M93 = graph.insert_node("CLL 20 - AV 6");
	auto M94 = graph.insert_node("CLL 20 - AV 7");
	auto M95 = graph.insert_node("CLL 20 - AV 8");
	auto M96 = graph.insert_node("CLL 21 - AV 3");
	auto M97 = graph.insert_node("CLL 21 - AV 4");
	auto M98 = graph.insert_node("CLL 21 - AV 5");
	auto M99 = graph.insert_node("CLL 21 - AV 6");
	auto M100 = graph.insert_node("CLL 21 - AV 7");
	auto M101 = graph.insert_node("CLL 21 - AV 8");
	auto M102 = graph.insert_node("CLL 22 - AV 5");
	auto M103 = graph.insert_node("CLL 22 - AV 6");
	auto M104 = graph.insert_node("CLL 22 - AV 7");
	auto M105 = graph.insert_node("CLL 22 - AV 8");
	auto M106 = graph.insert_node("CLL 23 - AV 4");
	auto M107 = graph.insert_node("CLL 23 - AV 5");
	auto M108 = graph.insert_node("CLL 23 - AV 6");
	auto M109 = graph.insert_node("CLL 23 - AV 7");
	auto M110 = graph.insert_node("CLL 23 - AV 8");
	auto M110a = graph.insert_node("CLL 24 - AV 2");
	auto M111 = graph.insert_node("CLL 24 - AV 3");
	auto M112 = graph.insert_node("CLL 24 - AV 4");
	auto M113 = graph.insert_node("CLL 24 - AV 5");
	auto M114 = graph.insert_node("CLL 24 - AV 6");
	auto M115 = graph.insert_node("CLL 24 - AV 7");
	auto M116 = graph.insert_node("CLL 24 - AV 8");
	auto M117 = graph.insert_node("CLL 24 - ?av");
	auto M118 = graph.insert_node("CLL 24 - CLL 25");
	auto M119 = graph.insert_node("CLL 25 - AV 2");
	auto M120 = graph.insert_node("CLL 25 - AV 3");
	auto M121 = graph.insert_node("CLL 25 - AV 4");
	auto M122 = graph.insert_node("CLL 25 - AV 5");
	auto M123 = graph.insert_node("CLL 25 - AV 6");
	auto M124 = graph.insert_node("CLL 25 - AV 7");
	auto M125 = graph.insert_node("CLL 25 - AV 8");
	auto M126 = graph.insert_node("CLL 25 - ?av");
	auto M127 = graph.insert_node("CLL 25 - ?av1");
	auto M128 = graph.insert_node("CLL Extra de la av 8 - AV  extra cerca del teleferico");
	auto M129 = graph.insert_node("CLL Extra 2 de la av 8 - AV  extra cerca del teleferico");
	auto M130 = graph.insert_node("CLL 26 - AV 8");
	auto M131 = graph.insert_node("CLL ? - AV 8");
	auto M132 = graph.insert_node("CLL 26 - AV 2");
	auto M133 = graph.insert_node("CLL 26 - AV 3");
	auto M134 = graph.insert_node("CLL 26 - AV 4");
	auto M135 = graph.insert_node("CLL 26 - AV 5");
	auto M136 = graph.insert_node("CLL 26 - AV 6");
	auto M137 = graph.insert_node("CLL 26 - AV 7");
	auto M138 = graph.insert_node("CLL 27 - AV 2");
	auto M139 = graph.insert_node("CLL 27 - AV 3");
	auto M140 = graph.insert_node("CLL 27 - AV 4");
	auto M141 = graph.insert_node("CLL 28 - AV 2");
	auto M142 = graph.insert_node("CLL 28 - AV 3");
	auto M143 = graph.insert_node("CLL 28 - AV 4");
	auto M144 = graph.insert_node("CLL 29 - AV 2");
	auto M145 = graph.insert_node("CLL 29 - AV 3");
	auto M146 = graph.insert_node("CLL 29 - AV 4");
	auto M147 = graph.insert_node("CLL 30 - AV 2");
	auto M148 = graph.insert_node("CLL 30 - AV 3");
	auto M149 = graph.insert_node("CLL 30 - AV 4");
	auto M150 = graph.insert_node("CLL 31 - AV 2");
	auto M151 = graph.insert_node("CLL 31 - AV 3");
	auto M152 = graph.insert_node("CLL 31 - AV 4");
	auto M153 = graph.insert_node("Milagrosa - Chorros 2");
	auto M154 = graph.insert_node("Chorros - Geografia");
	auto M155 = graph.insert_node("Amparo - Chorros - Forestal");
	auto M156 = graph.insert_node("Chorros - pasaje 1 Chorros");
	auto M157 = graph.insert_node("Chorros - pasaje 2 Chorros");
	auto M158 = graph.insert_node("Chorros - Forestal - Tia Mila");
	auto M158a = graph.insert_node("Ciclo Basico");
	auto M159 = graph.insert_node("Dentro de forestales");
	auto M160 = graph.insert_node("CEFAP");
	auto M161 = graph.insert_node("Chorros - Pasaje Quintero");
	auto M162 = graph.insert_node("Chorros - Calle 1 Chorros");
	auto M163 = graph.insert_node("Chorros - Mas arriba calle 1 Chorros");
	auto M164 = graph.insert_node("Chorros -  Cll. EL Conuco");
	auto M165 = graph.insert_node("Enlace Chorros - Hechicera");
	auto M166 = graph.insert_node("Redoma de los chorros - Zoologico");
	auto M167 = graph.insert_node("Chorros Calles 1 2 y 3");
	auto M168 = graph.insert_node("Autolavado - Recta Hechicera - San Pedro");
	auto M169 = graph.insert_node("Primera entrada Ingenieria");
	auto M170 = graph.insert_node("Parada de BIACI");
	auto M171 = graph.insert_node("Arquitectura");
	auto M172 = graph.insert_node("Entrada Sta. Rosa");
	auto M173 = graph.insert_node("Otra entrada Deportes");
	auto M174 = graph.insert_node("Estadio Bajando - Recta Hechicera");
	auto aux1 = graph.insert_node("Hechicera - Nodo Auxiliar");
	auto M175 = graph.insert_node("Bifurcacion");
   auto M175a = graph.insert_node("Bifurcacion 2");
	auto M176 = graph.insert_node("Conjunto Residencial la Hechicera 1");
	auto M177 = graph.insert_node("CC la Hechicera");
	auto M178 = graph.insert_node("Conjunto Residencial la Hechicera 2");
	auto M179 = graph.insert_node("Entrada sta. Ana");
	auto M180 = graph.insert_node("La Escena Bar");
	auto M181 = graph.insert_node("Jardin Botanico");
	auto M182 = graph.insert_node("Estacion de Servicio la Hechicera");
	auto M183 = graph.insert_node("Mukumbarila");
	auto M184 = graph.insert_node("Av Universidad -  Calle Yagrumo");
	auto M185 = graph.insert_node("Av Universidad - El Bosque");
	auto M186 = graph.insert_node("El Amparo");
	auto M186a = graph.insert_node("Av Universidad - Chorros");
	auto M187 = graph.insert_node("El Amparo - El Bosque");
	auto M188 = graph.insert_node("El Bosque");
	auto M189 = graph.insert_node("Albarregas 1");
	auto M190 = graph.insert_node("Albarregas 2");
	auto M191 = graph.insert_node(" CLL 32 - AV 2");
	auto M192 = graph.insert_node(" CLL 33 - AV 2");
	auto M193 = graph.insert_node(" CLL 34 - AV 2");
	auto M194 = graph.insert_node(" CLL 35 - AV 2");
	auto M195 = graph.insert_node(" CLL 36 - AV 2");
	auto M196 = graph.insert_node(" CLL 37 - AV 2");
	auto M197 = graph.insert_node(" CLL 32 - AV 3");
	auto M198 = graph.insert_node(" CLL 33 - AV 3");
	auto M199 = graph.insert_node(" CLL 34 - AV 3");
	auto M200 = graph.insert_node(" CLL 35 - AV 3");
	auto M201 = graph.insert_node(" CLL 36 - AV 3");
	auto M202 = graph.insert_node(" CLL 32 - AV 4");
	auto M203 = graph.insert_node(" CLL 33 - AV 4");
	auto M204 = graph.insert_node(" CLL 34 - AV 4");
	auto M205 = graph.insert_node(" CLL 35 - AV 4");
	auto M206 = graph.insert_node(" CLL 36 - AV 4");
	auto M207 = graph.insert_node(" CLL 37 - AV 3");
	auto M208 = graph.insert_node(" CLL 37 - AV Gonzalo Picon");
	auto M209 = graph.insert_node(" CLL B6A - AV Gonzalo Picon");
	auto M210 = graph.insert_node(" CLL 37 - AV Gonzalo Picon");
	auto M211 = graph.insert_node(" CLL B6A - AV Don Tulio");
	auto M212 = graph.insert_node(" CLL 36 - AV Don Tulio");
	auto M213 = graph.insert_node(" AV 2 - Viaducto Miranda");
	auto M214 = graph.insert_node(" AV 3 o Urdaneta con Viaducto Miranda");
	auto M215 = graph.insert_node(" AV Gonzalo Picon - Viaducto");
	auto M216 = graph.insert_node(" Ghersy");
	auto M217 = graph.insert_node(" Mercado Principal");
	auto M218 = graph.insert_node(" CLL B6B - AV Don Tulio");
	auto M219 = graph.insert_node(" CLL B6C - AV Don Tulio");
	auto M220 = graph.insert_node(" CLL B6D - AV Don Tulio");
	auto M221 = graph.insert_node(" CLL B6B - AV Gonzalo Picon");
	auto M222 = graph.insert_node(" CLL B6C - AV Gonzalo Picon");
	auto M223 = graph.insert_node(" CLL B6D - AV Gonzalo Picon");
	auto M224 = graph.insert_node(" AV Don Tulio - Paseo La Feria");
	auto M225 = graph.insert_node(" AV Don Tulio - CLL 30");
	auto M226 = graph.insert_node(" MOVISTAR");
	auto M227 = graph.insert_node(" INPSASEL");
	auto M228 = graph.insert_node(" Cruz Verde - AV Las Americas");
	auto M229 = graph.insert_node("Zarzamora");
	auto M230 = graph.insert_node(" Yuan Lin");
	auto M231 = graph.insert_node(" Viaducto Campo Elias");
	auto M232 = graph.insert_node(" Auxiliar Impsasel");
	auto M233 = graph.insert_node(" Auxiliar Movistar");
	auto M234 = graph.insert_node(" Entrada el Campito");
	auto M235 = graph.insert_node(" Arzobispo Silva");
	auto M236 = graph.insert_node(" La Nota Las Americas");
	auto M237 = graph.insert_node(" PF1");
	auto M238 = graph.insert_node(" PF2");
	auto M239 = graph.insert_node(" PF3");
	auto M240 = graph.insert_node(" PF4");
	auto M241 = graph.insert_node(" Pizzarito");
	auto M242 = graph.insert_node(" TrolCable");
	auto M243 = graph.insert_node(" Cardenal Quintero");
	auto M244 = graph.insert_node(" Sor Juana Inés");
	auto M245 = graph.insert_node(" CLL 27 - AV Don Tulio");
	auto M246 = graph.insert_node(" CLL 28 - AV Don Tulio");
	auto M247 = graph.insert_node(" CLL 29 - AV Don Tulio");
	auto M248 = graph.insert_node(" CLL 30 - AV Don Tulio");
	auto M249 = graph.insert_node(" CLL 31 - AV Don Tulio");
	auto M250 = graph.insert_node(" CLL 32 - AV Don Tulio");
	auto M251 = graph.insert_node(" CLL 33 - AV Don Tulio");
	auto M252 = graph.insert_node(" CLL 34 - AV Don Tulio");
	auto M253 = graph.insert_node(" CLL 35 - AV Don Tulio");



// auto nombre = GT.insert_node('value');

//GT.insert_arc(src,target,weight)

//Ahora todos los Arcos

  graph.insert_arc(M1E,M1,144.75);
  graph.insert_arc(M1,M1E,144.75);
  graph.insert_arc(M1,M2,40.92);
  graph.insert_arc(M2,M1,40.92);
  graph.insert_arc(M2,M2E,179.01);
  graph.insert_arc(M2,MR5A,43.2);
  graph.insert_arc(M2E,M2,179.01);
  graph.insert_arc(MR5A,M2,43.2);
  graph.insert_arc(MR5A,MCSF,156.25);
  graph.insert_arc(MR5A,M185,616.64);
//graph.insert_arc(MCSF,MR5A,156.25);
  graph.insert_arc(MCSF,MCSD0,52.15);
  graph.insert_arc(MCSD0,MCSF,52.15);
  graph.insert_arc(MCSD0,MCSD1,78.42);
  graph.insert_arc(MCSD1,MCSD2,110.76);
  graph.insert_arc(MCSD2,MCSD3,69.52);
  graph.insert_arc(MCSD3,MCSD0,104.92);
  graph.insert_arc(M185,M186a,202.82);
  graph.insert_arc(M185,M188,46.03);
  graph.insert_arc(M186a,M21,110.48);
  graph.insert_arc(M186a,M19,53.32);
  graph.insert_arc(M188,M185,46.03);
  graph.insert_arc(M188,M187,48.08);
  graph.insert_arc(M19,M184,460.11);
  graph.insert_arc(M19,M21,99.97);
  graph.insert_arc(M19,M16,718.74);
  graph.insert_arc(M184,MR5A,404.99);
  graph.insert_arc(M184,M5,200.0);
  graph.insert_arc(M184,M20,63.39);
  graph.insert_arc(M187,M188,48.08);
  graph.insert_arc(M187,M186,164.38);
  graph.insert_arc(M186,M187,164.38);
  graph.insert_arc(M186,M155,161.44);
  graph.insert_arc(M155,M186,161.44);
  graph.insert_arc(M155,M154,118.39);
  graph.insert_arc(M155,M159,162.0);
  graph.insert_arc(M155,M156,464.47);
  graph.insert_arc(M21,M154,279.46);
  graph.insert_arc(M21,M153,163.8);
  graph.insert_arc(M153,M182,870.65);
  graph.insert_arc(M158a,M153,182.56);
  graph.insert_arc(M154,M158a,75.13);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M156,M155,484.47);
  graph.insert_arc(M156,M157,48.61);
  graph.insert_arc(M157,M156,48.61);
  graph.insert_arc(M157,M158,238.0);
  graph.insert_arc(M158,M157,238.0);
  graph.insert_arc(M158,M160,427.5);
  graph.insert_arc(M158,M161,176.08);
  graph.insert_arc(M159,M155,162.0);
  graph.insert_arc(M159,M160,307.4);
  graph.insert_arc(M160,M159,307.4);
  graph.insert_arc(M160,M158,427.5);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M161,M158,176.08);
  graph.insert_arc(M161,M162,59.63);
  graph.insert_arc(M162,M163,54.45);
  graph.insert_arc(M162,M161,59.63);
  graph.insert_arc(M163,M164,95.49);
  graph.insert_arc(M163,M162,54.45);
  graph.insert_arc(M164,M165,228.48);
  graph.insert_arc(M164,M163,95.49);
  graph.insert_arc(M165,M167,203.23);
  graph.insert_arc(M165,M164,228.48);
  graph.insert_arc(M165,M168,252.12);
  graph.insert_arc(M167,M165,42.19);
  graph.insert_arc(M167,M166,202.23);
  graph.insert_arc(M166,M167,42.19);
  graph.insert_arc(M168,M165,252.12);
  graph.insert_arc(M168,M175,170.0);
  graph.insert_arc(M168,M175a,372.93);
  graph.insert_arc(M168,aux1,100.49);
  graph.insert_arc(aux1,M175,103.6);
  graph.insert_arc(aux1,M169,290.53);
  graph.insert_arc(aux1,M168,100.49);
  graph.insert_arc(M175,aux1,103.6);
  graph.insert_arc(M175,M168,372.93);
  graph.insert_arc(M175,M174,379.01);
  graph.insert_arc(M169,aux1,100.49);
  graph.insert_arc(M169,M170,423.21);
  graph.insert_arc(M169,M173,464.62);
  graph.insert_arc(M170,M169,423.21);
  graph.insert_arc(M170,M171,222.33);
  graph.insert_arc(M171,M170,222.33);
  graph.insert_arc(M171,M172,156.83);
  graph.insert_arc(M172,M171,156.83);
  graph.insert_arc(M172,M173,118.12);
  graph.insert_arc(M173,M172,118.12);
  graph.insert_arc(M173,M174,254.41);
  graph.insert_arc(M174,M175a,100.0);
  graph.insert_arc(M174,M175,339.0);
  graph.insert_arc(M174,M173,254.41);
  graph.insert_arc(M175a,M174,100.0);
  graph.insert_arc(M175a,M168,372.93);
  graph.insert_arc(M175a,M176,57.6);
  graph.insert_arc(M176,M177,124.85);
  graph.insert_arc(M177,M178,81.15);
  graph.insert_arc(M178,M179,172.64);
  graph.insert_arc(M179,M180,189.39);
  graph.insert_arc(M180,M181,745.44);
  graph.insert_arc(M181,M175a,400.0);
  graph.insert_arc(M182,M179,150.0);
  graph.insert_arc(M182,M183,438.0);
  graph.insert_arc(M182,M190,59.29);
  graph.insert_arc(M183,M19,682.0);
  graph.insert_arc(M190,M182,59.29);
  graph.insert_arc(M190,M189,62.62);
  graph.insert_arc(M189,M190,62.62);
  graph.insert_arc(M189,M25,524.33);
  graph.insert_arc(M25,M189,524.33);
  graph.insert_arc(M25,M23,125.87);
  graph.insert_arc(M23,M25,125.87);
  graph.insert_arc(M23,M24,395.16);
  graph.insert_arc(M23,M22,431.88);
  graph.insert_arc(M24,M23,395.16);
  graph.insert_arc(M22,M27,123.5);
  graph.insert_arc(M27,M26,50.0);
  graph.insert_arc(M27,M29,119.31);
  graph.insert_arc(M26,M15,378.65);
  graph.insert_arc(M15,M16,55.39);
  graph.insert_arc(M15,M14,119.28);
  graph.insert_arc(M16,M17,87.55);
  graph.insert_arc(M16,M22,248.86);
  graph.insert_arc(M17,M14,67.24);
  graph.insert_arc(M17,M18,165.71);
  graph.insert_arc(M18,M19,478.32);
  graph.insert_arc(M18,M13,115.47);
  graph.insert_arc(M14,M13,148.48);
  graph.insert_arc(M13,M12,111.01);
  graph.insert_arc(M12,M9a,218.58);
  graph.insert_arc(M12,M11,97.07);
  graph.insert_arc(M9a,M19,238.91);
  graph.insert_arc(M11,M10,75.56);
  graph.insert_arc(M11,M6,110.96);
  graph.insert_arc(M11,M6,110.96);
  graph.insert_arc(M10,M7,90.32);
  graph.insert_arc(M10,M11,75.56);
  graph.insert_arc(M10,M9,64.39);
  graph.insert_arc(M9,M10,64.39);
  graph.insert_arc(M9,M9a,29.05);
  graph.insert_arc(M9,M8,78.06);
  graph.insert_arc(M8,M9,78.06);
  graph.insert_arc(M8,M7,67.16);
  graph.insert_arc(M7,M8,67.16);
  graph.insert_arc(M7,M10,90.32);
  graph.insert_arc(M7,M6,63.83);
  graph.insert_arc(M6,M7,63.83);
  graph.insert_arc(M6,MCET,138.6);
  graph.insert_arc(MCET,M6,138.6);
  graph.insert_arc(MCET,MCACM,50.11);
  graph.insert_arc(MCET,MR5A,780.89);
  graph.insert_arc(MCACM,MCET,50.11);
  graph.insert_arc(MCACM,MCLA,172.9);
  graph.insert_arc(MCACM,M3,117.4);
  graph.insert_arc(MCLA,MCACM,172.9);
  graph.insert_arc(MCLA,MCACP,118.15);
  graph.insert_arc(MCACP,MCLA,118.15);
  graph.insert_arc(MCACP,M3,172.5);
  graph.insert_arc(MCACP,M5,89.7);
  graph.insert_arc(M5,MCACP,89.7);
  graph.insert_arc(M5,M4,170.4);
  graph.insert_arc(M5,M20,205.23);
  graph.insert_arc(M4,M5,170.4);
  graph.insert_arc(M4,M3,89.58);
  graph.insert_arc(M3,M4,89.58);
  graph.insert_arc(M3,MCACM,117.4);
  graph.insert_arc(M3,MCACP,172.5);
  graph.insert_arc(M20,M5,205.23);
  graph.insert_arc(M20,M184,200.0);
  graph.insert_arc(M28,M29,92.92);
  graph.insert_arc(M28,M26,135.83);
  graph.insert_arc(M29,M30,93.85);
  graph.insert_arc(M30,M31,102.51);
  graph.insert_arc(M30,M33,115.73);
  graph.insert_arc(M31,M28,106.42);
  graph.insert_arc(M31,M32,122.8);
  graph.insert_arc(M32,M35,105.64);
  graph.insert_arc(M32,M42,110.14);
  graph.insert_arc(M33,M41,117.93);
  graph.insert_arc(M34,M31,94.85);
  graph.insert_arc(M36,M34,105.6);
  graph.insert_arc(M37,M36,86.5);
  graph.insert_arc(M35,M38,97.47);
  graph.insert_arc(M35,M34,116.78);
  graph.insert_arc(M38,M39,87.23);
  graph.insert_arc(M38,M44,130.27);
  graph.insert_arc(M39,M37,106.5);
  graph.insert_arc(M39,M40,100.34);
  graph.insert_arc(M40,M46,127.8);
  graph.insert_arc(M41,M48,82.64);
  graph.insert_arc(M41,M42,105.5);
  graph.insert_arc(M42,M43,103.72);
  graph.insert_arc(M42,M49,90.95);
  graph.insert_arc(M43,M44,100.0);
  graph.insert_arc(M43,M35,116.41);
  graph.insert_arc(M44,M45,88.13);
  graph.insert_arc(M44,M51,95.17);
  graph.insert_arc(M45,M46,103.45);
  graph.insert_arc(M45,M39,124.58);
  graph.insert_arc(M46,M47,33.92);
  graph.insert_arc(M46,M53,98.87);
  graph.insert_arc(M47,M54,97.39);
  graph.insert_arc(M48,M56,93.98);
  graph.insert_arc(M49,M48,113.24);
  graph.insert_arc(M49,M57,97.44);
  graph.insert_arc(M50,M43,95.58);
  graph.insert_arc(M50,M49,95.1);
  graph.insert_arc(M51,M59,97.87);
  graph.insert_arc(M51,M50,94.33);
  graph.insert_arc(M52,M45,101.26);
  graph.insert_arc(M52,M51,91.17);
  graph.insert_arc(M53,M52,103.4);
  graph.insert_arc(M53,M68,120.5);
  graph.insert_arc(M54,M53,58.0);
  graph.insert_arc(M54,M61,46.29);
  graph.insert_arc(M55,M54,106.48);
  graph.insert_arc(M65,M55,37.45);
  graph.insert_arc(M56,M57,112.85);
  graph.insert_arc(M56,M71,92.88);
  graph.insert_arc(M57,M58,96.24);
  graph.insert_arc(M57,M72,94.61);
  graph.insert_arc(M58,M50,99.29);
  graph.insert_arc(M58,M59,92.76);
  graph.insert_arc(M59,M60,93.72);
  graph.insert_arc(M59,M74,93.93);
  graph.insert_arc(M60,M52,102.2);
  graph.insert_arc(M60,M68,94.93);
  graph.insert_arc(M68,M63,77.56);
  graph.insert_arc(M68,M76,99.45);
  graph.insert_arc(M63,M64,99.61);
  graph.insert_arc(M63,M77,98.57);
  graph.insert_arc(M61,M62,104.46);
  graph.insert_arc(M61,M63,77.8);
  graph.insert_arc(M62,M55,48.92);
  graph.insert_arc(M62,M66,94.46);
  graph.insert_arc(M66,M65,170.92);
  graph.insert_arc(M64,M62,70.41);
  graph.insert_arc(M64,M67,99.5);
  graph.insert_arc(M67,M66,65.55);
  graph.insert_arc(M69,M64,56.69);
  graph.insert_arc(M69,M70,93.38);
  graph.insert_arc(M70,M67,56.69);
  graph.insert_arc(M71,M79,93.11);
  graph.insert_arc(M72,M71,102.54);
  graph.insert_arc(M72,M80,94.77);
  graph.insert_arc(M73,M58,95.93);
  graph.insert_arc(M73,M72,96.03);
  graph.insert_arc(M74,M73,92.77);
  graph.insert_arc(M74,M82,91.93);
  graph.insert_arc(M75,M60,96.22);
  graph.insert_arc(M75,M74,94.09);
  graph.insert_arc(M76,M75,93.94);
  graph.insert_arc(M76,M84,93.64);
  graph.insert_arc(M77,M76,90.96);
  graph.insert_arc(M77,M85,96.65);
  graph.insert_arc(M78,M69,49.95);
  graph.insert_arc(M78,M77,92.94);
  graph.insert_arc(M78,M87,94.32);
  graph.insert_arc(M87,M70,49.95);
  graph.insert_arc(M79,M80,93.34);
  graph.insert_arc(M79,M88,96.95);
  graph.insert_arc(M80,M81,92.35);
  graph.insert_arc(M80,M89,93.38);
  graph.insert_arc(M81,M73,97.93);
  graph.insert_arc(M81,M82,96.01);
  graph.insert_arc(M82,M83,91.76);
  graph.insert_arc(M82,M91,90.82);
  graph.insert_arc(M83,M75,94.52);
  graph.insert_arc(M83,M84,90.5);
  graph.insert_arc(M84,M85,95.15);
  graph.insert_arc(M84,M93,100.0);
  graph.insert_arc(M85,M86,95.06);
  graph.insert_arc(M85,M94,100.5);
  graph.insert_arc(M86,M78,104.75);
  graph.insert_arc(M88,M89,93.21);
  graph.insert_arc(M89,M110a,462.73);
  graph.insert_arc(M90,M81,92.63);
  graph.insert_arc(M90,M89,95.24);
  graph.insert_arc(M91,M90,90.79);
  graph.insert_arc(M91,M97,91.91);
  graph.insert_arc(M92,M83,95.46);
  graph.insert_arc(M92,M91,93.56);
  graph.insert_arc(M93,M92,92.27);
  graph.insert_arc(M93,M99,91.18);
  graph.insert_arc(M94,M93,94.17);
  graph.insert_arc(M94,M100,93.89);
  graph.insert_arc(M95,M86,95.81);
  graph.insert_arc(M95,M94,96.96);
  graph.insert_arc(M96,M90,93.42);
  graph.insert_arc(M96,M97,90.92);
  graph.insert_arc(M97,M98,93.67);
  graph.insert_arc(M97,M106,186.63);
  graph.insert_arc(M98,M92,91.54);
  graph.insert_arc(M98,M99,92.90);
  graph.insert_arc(M99,M100,94.24);
  graph.insert_arc(M99,M103,92.01);
  graph.insert_arc(M100,M101,96.36);
  graph.insert_arc(M100,M104,89.8);
  graph.insert_arc(M101,M95,94.67);
  graph.insert_arc(M102,M98,92.87);
  graph.insert_arc(M103,M102,95.17);
  graph.insert_arc(M103,M108,91.95);
  graph.insert_arc(M104,M103,92.01);
  graph.insert_arc(M104,M109,93.72);
  graph.insert_arc(M105,M101,88.53);
  graph.insert_arc(M105,M104,98.86);
  graph.insert_arc(M106,M112,91.89);
  graph.insert_arc(M107,M102,91.15);
  graph.insert_arc(M107,M106,93.66);
  graph.insert_arc(M108,M107,94.87);
  graph.insert_arc(M108,M114,91.64);
  graph.insert_arc(M109,M108,93.52);
  graph.insert_arc(M109,M115,99.13);
  graph.insert_arc(M110,M105,88.76);
  graph.insert_arc(M110,M109,99.45);
  graph.insert_arc(M110a,M111,93.76);
  graph.insert_arc(M110a,M119,91.58);
  graph.insert_arc(M111,M96,277.92);
  graph.insert_arc(M111,M112,92.32);
  graph.insert_arc(M112,M113,91.88);
  graph.insert_arc(M112,M121,93.42);
  graph.insert_arc(M113,M107,91.2);
  graph.insert_arc(M113,M114,91.37);
  graph.insert_arc(M114,M115,93.33);
  graph.insert_arc(M114,M123,95.56);
  graph.insert_arc(M115,M116,104.3);
  graph.insert_arc(M115,M124,93.09);
  graph.insert_arc(M116,M110,94.13);
  graph.insert_arc(M116,M117,132.21);
  graph.insert_arc(M117,M118,84.74);
  graph.insert_arc(M117,M126,131.2);
  graph.insert_arc(M118,M126,210.22);
  graph.insert_arc(M126,M127,36.21);
  graph.insert_arc(M127,M125,73.24);
  graph.insert_arc(M127,M128,57.67);
  graph.insert_arc(M128,M129,51.2);
  graph.insert_arc(M128,M131,68.83);
  graph.insert_arc(M129,M130,62.8);
  graph.insert_arc(M131,M125,58.4);
  graph.insert_arc(M130,M131,48.22);
  graph.insert_arc(M130,M137,106.84);
  graph.insert_arc(M125,M116,92.33);
  graph.insert_arc(M125,M124,106.62);
  graph.insert_arc(M124,M123,95.74);
  graph.insert_arc(M124,M137,110.0);
  graph.insert_arc(M123,M122,85.33);
  graph.insert_arc(M123,M136,110.0);
  graph.insert_arc(M122,M113,95.6);
  graph.insert_arc(M122,M121,96.61);
  graph.insert_arc(M121,M120,92.46);
  graph.insert_arc(M121,M134,110.0);
  graph.insert_arc(M120,M111,90.0);
  graph.insert_arc(M120,M119,99.57);
  graph.insert_arc(M119,M132,110.0);
  graph.insert_arc(M132,M138,102.84);
  graph.insert_arc(M133,M120,110.0);
  graph.insert_arc(M133,M132,92.95);
  graph.insert_arc(M133,M134,95.62);
  graph.insert_arc(M134,M133,95.62);
  graph.insert_arc(M134,M135,94.01);
  graph.insert_arc(M134,M140,93.09);
  graph.insert_arc(M135,M122,110.0);
  graph.insert_arc(M135,M134,94.01);
  graph.insert_arc(M135,M136,93.90);
  graph.insert_arc(M136,M135,93.90);
  graph.insert_arc(M136,M137,97.46);
  graph.insert_arc(M137,M130,106.84);
  graph.insert_arc(M137,M136,97.46);
  graph.insert_arc(M138,M139,94.03);
  graph.insert_arc(M138,M141,95.96);
  graph.insert_arc(M139,M133,96.9);
  graph.insert_arc(M139,M140,94.85);
  graph.insert_arc(M140,M143,100.39);

  graph.insert_arc(M143,M142,93.12);
  graph.insert_arc(M143,M146,88.59);
  graph.insert_arc(M142,M141,99.51);
  graph.insert_arc(M142,M139,97.29);
  graph.insert_arc(M141,M144,87.21);
  graph.insert_arc(M144,M145,91.1);
  graph.insert_arc(M144,M147,94.2);
  graph.insert_arc(M145,M142,88.4);
  graph.insert_arc(M145,M146,89.89);
  graph.insert_arc(M146,M149,84.4);
  graph.insert_arc(M149,M148,89.72);
  graph.insert_arc(M149,M152,96.72);
  graph.insert_arc(M148,M147,94.62);
  graph.insert_arc(M148,M145,91.68);
  graph.insert_arc(M147,M150,95.3);
  graph.insert_arc(M150,M151,90.05);
  graph.insert_arc(M151,M148,93.3);
  graph.insert_arc(M151,M152,87.9);
//  graph.insert_arc(M152,M153,88.0); Para Conectar hasta aqui

  graph.insert_arc(M150,M191,93.14);
  graph.insert_arc(M152,M202,93.24);
  graph.insert_arc(M152,M249,90.1);
  graph.insert_arc(M140,M245,94.44);
  graph.insert_arc(M146,M247,86.49);
  graph.insert_arc(M150,M151,90.05);

  graph.insert_arc(M191,M192,92.31);
  graph.insert_arc(M192,M193,87.63);
  graph.insert_arc(M193,M194,95.47);
  graph.insert_arc(M194,M195,95.38);
  graph.insert_arc(M194,M200,85.98);
  graph.insert_arc(M195,M196,88.36);
  graph.insert_arc(M195,M201,75.54);
  graph.insert_arc(M196,M213,212.07);
  graph.insert_arc(M196,M207,76.89);
  graph.insert_arc(M213,M217,330.31);
  graph.insert_arc(M213,M214,82.04);
  graph.insert_arc(M214,M213,82.04);
  graph.insert_arc(M214,M207,207.86);
  graph.insert_arc(M214,M215,138.65);
  graph.insert_arc(M215,M214,138.65);
  graph.insert_arc(M215,M223,61.21);
  graph.insert_arc(M215,M216,95.14);
  graph.insert_arc(M216,M215,95.14);
  graph.insert_arc(M216,M212,289.69);
  graph.insert_arc(M223,M222,59.64);
  graph.insert_arc(M223,M220,76.7);
  graph.insert_arc(M222,M221,59.32);
  graph.insert_arc(M221,M210,60.20);
  graph.insert_arc(M210,M215,200.74);
  graph.insert_arc(M210,M207,141.26);
  graph.insert_arc(M210,M209,57.65);
  graph.insert_arc(M209,M208,56.54);
  graph.insert_arc(M208,M210,90.68);
  graph.insert_arc(M208,M212,90.05);
  graph.insert_arc(M212,M211,57.84);
  graph.insert_arc(M212,M224,470.11);
  graph.insert_arc(M211,M209,76.7);
  graph.insert_arc(M211,M218,57.48);
  graph.insert_arc(M218,M219,56.9);
  graph.insert_arc(M218,M221,76.7);
  graph.insert_arc(M219,M220,59.1);
  graph.insert_arc(M219,M222,76.7);
  graph.insert_arc(M220,M216,63.33);
  graph.insert_arc(M207,M210,141.26);
  graph.insert_arc(M207,M214,207.86);
  graph.insert_arc(M207,M196,76.89);
  graph.insert_arc(M207,M201,91.33);
  graph.insert_arc(M201,M200,93.07);
  graph.insert_arc(M201,M206,84.93);
  graph.insert_arc(M200,M205,82.04);
  graph.insert_arc(M200,M199,92.21);
  graph.insert_arc(M199,M193,84.94);
  graph.insert_arc(M199,M198,92.24);
  graph.insert_arc(M198,M192,80.28);
  graph.insert_arc(M198,M197,96.50);
  graph.insert_arc(M197,M191,83.22);
  graph.insert_arc(M197,M151,90.61);
  graph.insert_arc(M202,M197,86.18);
  graph.insert_arc(M202,M203,90.05);
  graph.insert_arc(M203,M198,86.56);
  graph.insert_arc(M203,M204,93.31);
  graph.insert_arc(M204,M205,94.35);
  graph.insert_arc(M204,M199,84.16);
  graph.insert_arc(M205,M206,91.00);
  graph.insert_arc(M205,M253,84.3);
  graph.insert_arc(M206,M208,58.66);
  graph.insert_arc(M135,M245,89.54);
  graph.insert_arc(M245,M246,100.26);
  graph.insert_arc(M246,M247,96.01);
  graph.insert_arc(M246,M143,96.15);
  graph.insert_arc(M247,M248,73.19);
  graph.insert_arc(M248,M249,104.67);
  graph.insert_arc(M248,M149,92.15);
  graph.insert_arc(M249,M250,91.27);
  graph.insert_arc(M249,M224,23.10);
  graph.insert_arc(M250,M202,84.97);
  graph.insert_arc(M250,M251,99.36);
  graph.insert_arc(M251,M203,84.0);
  graph.insert_arc(M251,M252,85.45);
  graph.insert_arc(M252,M204,88.20);
  graph.insert_arc(M252,M253,102.68);
  graph.insert_arc(M253,M212,94.07);
  graph.insert_arc(M224,M225,105.42);
  graph.insert_arc(M224,M237,77.03);
  graph.insert_arc(M225,M248,24.3);
  graph.insert_arc(M225,M135,358.08);
  graph.insert_arc(M237,M238,80.26);
  graph.insert_arc(M238,M225,72.38);
  graph.insert_arc(M238,M239,172.13);
  graph.insert_arc(M238,M240,109.79);
  graph.insert_arc(M239,M241,98.12);
  graph.insert_arc(M241,M240,141.75);
  graph.insert_arc(M241,M242,100.63);
  graph.insert_arc(M242,M240,198.35);
  graph.insert_arc(M242,M129,157.10);
  graph.insert_arc(M129,M242,157.10);
  graph.insert_arc(M240,M238,109.79);
  graph.insert_arc(M240,M241,141.75);
  graph.insert_arc(M240,M242,198.35);
  graph.insert_arc(M144,M228,515.69);
  graph.insert_arc(M217,M213,330.31);
  graph.insert_arc(M217,M226,283.56);
  graph.insert_arc(M226,M233,101.00);
  graph.insert_arc(M226,M227,94.10);
  graph.insert_arc(M233,M226,101.00);
  graph.insert_arc(M233,M232,100.65);
  graph.insert_arc(M232,M233,100.65);
  graph.insert_arc(M232,M227,101.00);
  graph.insert_arc(M227,M232,101.00);
  graph.insert_arc(M227,M236,20.42);
  graph.insert_arc(M227,M228,425.82);
  graph.insert_arc(M228,M144,515.69);
  graph.insert_arc(M228,M229,259.17);
  graph.insert_arc(M229,M231,106.99);
  graph.insert_arc(M229,M230,116.75);
  graph.insert_arc(M230,M132,351.35);
  graph.insert_arc(M132,M230,351.35);
  graph.insert_arc(M230,M234,334.56);
  graph.insert_arc(M230,M243,576.37);
  graph.insert_arc(M230,M244,505.91);
  graph.insert_arc(M231,M132,276.26);
  graph.insert_arc(M243,M230,576.37);
  graph.insert_arc(M244,M25,644.28);
  graph.insert_arc(M234,M235,133.90);
  graph.insert_arc(M235,M229,27.57);
  graph.insert_arc(M236,M227,20.42);
  graph.insert_arc(M236,M217,90.05);
 // print_graph(graph);
Aleph::Dijkstra_Min_Paths<GT> dijkstra;
//ofstream out("ejemplo.dot");
//To_Graphviz<GT> gv;
//gv(graph, out);
//out.close();
//esto fue para imprimir el grafo pero es muy pesado 

if (Tarjan_Connected_Components<GT>().test_connectivity(graph))
  cout << "Conexo" << endl;
else
cout << "NO Conexo" << endl;		//esta es una prueba de conectividad para digrafos

Path<GT> camino(graph);		//este es un camino
 //Creo una variable donde se encuentra el algoritmo dijkstra
 dijkstra(graph,MCACM,M144,camino); //Ejecuto el codigo dijkstra para el grafo "graph", empezando en M1 y guardando el arbol abarcados en el dijkstra_test
	

if (camino.is_empty())
cout << "no hay camino" << endl;
else
cout << "hay Camino" << endl;	 //verifico que, en efecto, existe un camino
float distance = 0.0;
int counter = 0;


//fuerza bruta

std::map<int,Node*> ds1;

ds1[0]=M1E;
ds1[1]=M170;
ds1[2]=M144;
ds1[3]=M37;


Node* todos[4] = {M34,M150,MCACM,M78}; //creo un array de los 4 posibles destinos
int comb[23][4];//aca todas las posibles combinaciones

for(int i = 0;i<4;i++)
{
	for(int j = 0; j < 4;j++)
	{
		if (j != i)
		{
			for(int k = 0;k<4;k++)
			{
				if(k!=i && k!=j)
				{
					for(int l = 0;l<4;l++)
					{
						if((l!=i)&&(l!=j)&&(l!=k))
						{
							
							comb[counter][0] = i;
							comb[counter][1] = j;
							comb[counter][2] = k;
							comb[counter][3] = l;
							counter++;
							cout << i << j << k << l << counter<< endl;
						}
					}
				}
			}
		}
	}
}//esto las saca al peli

for(int m = 0;m<24;m++)
{
	for(int n = 0;n<4;n++)
	{
		cout << comb[m][n];
	}
	cout << endl;
}//aca las verifico

Node* nodo_Origen = M242;//no hace falta, de momento
float dist[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};//quiero almacenar las 24 distancias en un array para luego hacer cualquier tipo de sort

for(int m = 0;m<24;m++)
{
	for(int n = 0;n<4;n++)
	{
		if(n != 3)
		{
			int aux=comb[m][n];
			int aux2=comb[m][n+1];
			dijkstra(graph,nodo_Origen,ds1[aux],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				//auto p = it.get_current_node();
				if(it.is_in_last())
				{
					break;
				}
				auto a = it.get_current_arc();
				//cout << "Node " << p->get_info() << ", "
	   		//<< endl;
 				dist[m] = dist[m] + a->get_info();
				//cout << "con una distancia total de " << distance << "metros "
	   		//<< endl;

			}
			dijkstra(graph,ds1[aux],ds1[aux2],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				//auto p = it.get_current_node();
				if(it.is_in_last())
				{
					break;
				}
				auto a = it.get_current_arc();
				//cout << "Node " << p->get_info() << ", "
	   		//<< endl;
 				dist[m] = dist[m] + a->get_info();
				//cout << "con una distancia total de " << distance << "metros "
	   		//<< endl;

			}
		}
	}	
}//aqui es donde se cae

/*for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
		{
			auto p = it.get_current_node();
			auto a = it.get_current_arc();
			cout << "Node " << p->get_info() << ", "
	   	<< endl;
 			distance = distance + a->get_info();
			cout << "con una distancia total de " << distance << "metros "
	   	<< endl;

		} //esta rutina imprime el camino creado al principio pero se cae en is_in_last() porque asi viene por defecto entonces no se como quitar esa condicion para tener acceso completo al camino
*/



  //print_graph(graph); //imprimo el arbol abarcador   
for(int m = 0;m<24;m++)
{ 

 cout << dist[m]<<endl;

}

//ordeno con burbuja de momento


for(int z = 1;z<24;z++)
{
	for (int v =0; v < (24-z);v++)
	{
		if(dist[v] > dist[v + 1])
		{
			float aux = dist[v];
			dist[v] = dist[v + 1];
			dist[v+1] = aux;
			int aa1 = comb[v][0];
			int aa2 = comb[v][1];
			int aa3 = comb[v][2];
			int aa4 = comb[v][3]; 
			comb[v][0] = comb[v + 1][0];
			comb[v][1] = comb[v + 1][1];
			comb[v][2] = comb[v + 1][2];
			comb[v][3] = comb[v + 1][3];
			comb[v+1][0] = aa1;
			comb[v+1][1] = aa2;
			comb[v+1][2] = aa3;
			comb[v+1][3] = aa4;
		}
	}
}

for(int m = 0;m<24;m++)
{ 

 cout << dist[m]<<endl;

}
for(int m = 0;m<24;m++)
{
	for(int n = 0;n<4;n++)
	{
		cout << comb[m][n];
	}
	cout << endl;
}

cout<<"el camino minimo, partiendo desde "<<nodo_Origen->get_info()<<endl<<"es el correspondiente a ir primero a: "<<ds1[comb[0][0]]->get_info()<<endl<<" en segundo lugar ir a: "<<ds1[comb[0][1]]->get_info()<<endl<<" En tercer lugar, ir a: "<<ds1[comb[0][2]]->get_info()<<endl<<" y por ultimo ir a: "<< ds1[comb[0][3]]->get_info()<<endl<<"con una distancia total de: "<<dist[0]<<" metros"<<endl<<"y la ruta es: "<<endl;
	

			dijkstra(graph,nodo_Origen,ds1[comb[0][0]],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				auto p = it.get_current_node();
				//if(it.is_in_last())
				//{
					//break;
				//}
				cout << p->get_info() <<endl;


			}

if (camino.is_empty())
cout << "no hay camino" << endl;
else
cout << "hay Camino" << endl;	




			dijkstra(graph,ds1[comb[0][0]],ds1[comb[0][1]],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				auto p = it.get_current_node();
				//if(it.is_in_last())
				//{
					//break;
				//}
				cout<< p->get_info() <<endl;
	   	}

			dijkstra(graph,ds1[comb[0][1]],ds1[comb[0][2]],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				auto p = it.get_current_node();
				//if(it.is_in_last())
				//{
					//break;
				//}
				cout<< p->get_info() <<endl;
	   	}

			dijkstra(graph,ds1[comb[0][2]],ds1[comb[0][3]],camino);
			for(Path<GT>::Iterator it(camino);it.has_current_node();it.next())
			{
				auto p = it.get_current_node();
				//if(it.is_in_last())
				//{
					//break;
				//}
				cout<< p->get_info() <<endl;
	   	}

	
 
  return 0;
}
