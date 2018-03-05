//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2018-02-24
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Martin Kobelka
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>
#include <stdint.h>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

namespace BlackBoxTesty {
    
    using namespace ::testing;
    
    /**
     * Test case for empty tree
     */
    class EmptyTree : public Test {
        
    protected:
        BinaryTree tree;
        
        
    };
    
    /**
     * Test case for non empty tree
     */
    class NonEmptyTree : public Test {
        
        protected:
            BinaryTree tree;
            
            int items[6] = {1, 56, 23, 89, 46, 78}; 
            
            int count_of_items = 6;
            
        
        void SetUp() override {
            
            // Add items into tree
            for (int i = 0; i < count_of_items; i++) {
                tree.InsertNode(items[i]);
            }    
        }
        
    };
    
    /**
     * Test case for Tree axioms
     */
    class TreeAxioms : public Test {
        
        protected:
            BinaryTree tree;
            
            int items[1000] = {
                134882901, 853971921, 2052445876, 757517739, 406758174, 
                1363440955, 1462687039, 1367646211, 1242463006, 667697617, 
                526795231, 1736978348, 296634763, 1428821748, 937906391, 
                663329170, 1150377528, 1730410455, 320026247, 1858647224, 
                745169088, 1052811244, 7292168, 487306502, 1648623699, 
                2140571430, 77332275, 126752390, 1352229151, 2048383104, 
                652642893, 1487112053, 754871377, 557605121, 97146144, 
                1161629551, 1921046076, 1559833183, 381792114, 1016025434, 
                80047152, 908587346, 605520135, 376681916, 189925446, 
                1543426526, 1040011086, 1340302974, 1126353334, 1360037333, 
                1051466550, 1871522422, 265364929, 1058758719, 211345276, 
                1913988629, 1051846501, 288677552, 2040741019, 256592005, 
                189577008, 545900264, 1743704058, 944448385, 1103505385, 
                1840850202, 2106077936, 877067813, 1253199737, 340386402, 
                1893093248, 1333246890, 1248973748, 351129735, 1709928806, 
                1438899195, 1894556261, 602456244, 631718521, 873425947, 
                1962493578, 1683185072, 597464721, 80374859, 594460143, 
                808809998, 1994363488, 1646306644, 1097487550, 1887620860, 
                1902898649, 1287064558, 286037476, 1499119059, 84029295, 
                1389542862, 1192485613, 42623583, 119127027, 298201703, 
                383009985, 2012220275, 1631448593, 1631983734, 215866362, 
                1193893751, 923399281, 2110422624, 1796349995, 1555117802, 
                836364923, 1611359925, 1090819226, 1433829645, 1691734785, 
                1685279369, 95155995, 1538614625, 1184102366, 1192643545, 
                1278751837, 939517367, 332224455, 1564789314, 291152779, 
                416253750, 806848528, 1483638392, 458877333, 925975555, 
                1781840095, 841887318, 790712183, 1265805040, 326387404, 
                1006578545, 312215143, 1249786685, 969517521, 2108565139, 
                657420840, 1805882445, 1572441416, 1748240066, 1092228442, 
                1116692553, 1286035788, 1187384437, 507823531, 322654506, 
                232544334, 1786575368, 1262171873, 564768789, 1203881034, 
                1553324652, 981022539, 2010729562, 889479397, 1439899872, 
                789221470, 523835844, 134303542, 1579933653, 1789640885, 
                460690947, 439028550, 2101856028, 1710477632, 1408546072, 
                2062937519, 220414824, 1066944869, 1487895288, 1968654891, 
                11689663, 457104193, 1107207031, 1199074100, 964927724, 
                1429861537, 1431618434, 604019445, 544549762, 1996387223, 
                1807900479, 2097874415, 829926114, 1671146394, 839870164, 
                122342338, 312884216, 1363706008, 256645880, 1892817869, 
                1005863245, 717336827, 184362771, 960235626, 280330812, 
                1592908843, 875689497, 500745636, 512370064, 216101137, 
                321916879, 524059727, 673205331, 1429123910, 1723133827, 
                1638133055, 711501799, 1007268613, 94668852, 1256051562, 
                856172188, 1902569332, 1206442329, 1686098302, 1426232078, 
                2046312493, 1808440640, 1739116294, 1262534853, 2065086521, 
                1484450515, 120914451, 634939700, 1668813286, 1081150077, 
                915270512, 1114238482, 1956839574, 1416016149, 1626608546, 
                25457064, 1737933028, 3184626, 698662395, 1019573291, 
                1726318453, 189311802, 1731075090, 586103419, 283980655, 
                839643004, 1442275607, 39066339, 2046085333, 980890262, 
                1465298417, 1944914178, 641847254, 1056931063, 1059965384, 
                559450127, 393897930, 1180879835, 1194389828, 2062711216, 
                114546264, 2109660340, 1029466050, 2071385838, 1378192841, 
                508590949, 2096842902, 968642222, 511775575, 648021649, 
                1988215513, 90610380, 837333452, 1571806955, 676713799, 
                1121314107, 263966312, 2118989407, 1160380446, 162567997, 
                952396021, 478195215, 2107482176, 1594243275, 1535126278, 
                1019963912, 6209755, 1929024208, 53360099, 1200599583, 
                1844251776, 167906363, 1162776275, 726234179, 91808553, 
                393485469, 1234825128, 41167808, 1362127691, 1746600703, 
                689189457, 1202859556, 1837211083, 1526522909, 627182863, 
                366441235, 500353368, 891149175, 337946994, 1660733814, 
                1053717173, 1290343015, 2138929029, 1013715701, 737102642, 
                1526571659, 2033679613, 743312397, 1308112219, 2087039712, 
                1943911980, 1004880348, 107462427, 959204608, 1731114527, 
                199270980, 1352690077, 818456007, 240438788, 567334120, 
                417573062, 929628246, 1770193676, 107300497, 308667507, 
                249892891, 473741732, 809020876, 1141042067, 811688726, 
                322271042, 47275592, 2102031741, 313716424, 1060991293, 
                691650736, 1840288083, 947187258, 1434963133, 1000916655, 
                886743322, 1231391466, 2005797003, 994205749, 43112426, 
                1589427882, 1193476729, 1395802503, 260400241, 1433915518, 
                1963136623, 677973303, 216060116, 1585846651, 785273800, 
                524727623, 1835739542, 1259015533, 1333748499, 829297961, 
                2070704259, 1656019542, 876573553, 2025252353, 1969735966, 
                1937564846, 569419441, 1662540401, 737268456, 2004382574, 
                515973408, 1624011778, 1088290392, 374286763, 470733879, 
                1131402818, 1963714645, 1664210609, 379721673, 76631238, 
                950642479, 195374648, 754604541, 1166702595, 1781221299, 
                1539878342, 1691430218, 1469477194, 651410227, 877695070, 
                151291507, 574630838, 386230964, 1027865061, 452399543, 
                208483282, 817946259, 1021818984, 1871023683, 1555214716, 
                878717911, 239513444, 1031742846, 1967008303, 613800207, 
                1502476726, 950927474, 430031205, 1019203687, 1330649147, 
                506662443, 1969846166, 1526023796, 1261266985, 989065113, 
                1159761447, 653661679, 533011683, 481754993, 1305071906, 
                1410706753, 633046501, 1879702744, 1796937717, 1660911562, 
                184618640, 2005420999, 331374173, 1206437624, 1728961035, 
                1886588889, 2085155535, 1968474479, 770848088, 1904680191, 
                434791038, 125841166, 708124017, 864822243, 1145044853, 
                2038773164, 1371484687, 967407371, 1417313312, 485268024, 
                1956472484, 429591112, 1138929703, 342000519, 911346105, 
                296517961, 1752707273, 1544392606, 28737057, 1402161342, 
                1057820520, 213355697, 1260098694, 1389194694, 1419793322, 
                841576081, 1128299935, 1357465209, 662566912, 1899148023, 
                1114661752, 1097357950, 2024989189, 1822785769, 1962180194, 
                1022550394, 1714075286, 1186181233, 1989957765, 983904950, 
                1671449257, 1798946601, 1413496062, 662895312, 2140947121, 
                177358520, 959413273, 1746170746, 1721751126, 988150330, 
                1000848440, 632087999, 1201506028, 113463486, 2021282693, 
                473815702, 955039567, 1002098980, 1831280911, 1617606479, 
                753763356, 798459016, 567480782, 631268897, 473761137, 
                382177328, 1653819292, 40352775, 1568358561, 1496293409, 
                1024257726, 1092324170, 1147756363, 290270140, 1755219482, 
                1141219836, 467628660, 567149107, 739906934, 41896139, 
                1555299437, 1740755374, 673984138, 609321817, 1854218861, 
                547783183, 1083137519, 661774780, 1549882163, 766934783, 
                131897612, 156161871, 1565393799, 699378394, 787430769, 
                2039154936, 1081555722, 293766413, 2079507712, 502430635, 
                1790059822, 956281790, 1594754805, 790332537, 1246551930, 
                1202490639, 1931552373, 1714180591, 1769639746, 523975659, 
                1756076730, 1177455535, 117247386, 282577220, 1786777353, 
                1971466247, 830360403, 722431224, 485757379, 232758918, 
                1489366007, 617654991, 388920790, 907276158, 1317033385, 
                1176351559, 798947447, 251105459, 1470117972, 730971511, 
                753536094, 1112694146, 1687253301, 200807251, 1903026684, 
                786321583, 1403297890, 1687095409, 353018526, 1025453988, 
                63587421, 2109095256, 55425876, 180834807, 244188828, 
                1842203229, 4817406, 1074549231, 417150805, 490574785, 
                1307308150, 1906516813, 1108229777, 1696228940, 666309323, 
                277779514, 725096851, 1465256770, 528884974, 47731175, 
                48744633, 1282421068, 1160425321, 1735997934, 1483228320, 
                915968357, 374835870, 739042562, 455580119, 727854396, 
                1764496551, 519167540, 689466005, 1819922427, 700002347, 
                933654833, 1514642008, 704819753, 2008204065, 1931792813, 
                1195394538, 1168028567, 1690825978, 156140667, 716773859, 
                209651654, 433920182, 1441870710, 1674908424, 962805156, 
                1489601885, 1723653058, 97742576, 502543558, 1312167344, 
                1580970896, 1418511916, 1687003214, 172529811, 1874092035, 
                267373963, 1937026362, 245775927, 956839968, 1609465141, 
                945778274, 1890494801, 976623501, 1650598027, 1751215218, 
                760932666, 698508917, 771760137, 304274997, 854649585, 
                1488533996, 513926651, 1288569767, 782921058, 41351427, 
                103891275, 125039295, 1765004485, 201633851, 627582854, 
                929688182, 1782604748, 2046094770, 469207748, 1955134559, 
                1772703157, 736581711, 1744677273, 2018479084, 1693421679, 
                1206658766, 816773710, 1436432833, 35798619, 319888089, 
                1040164403, 796731285, 1018397006, 1811924541, 1101006282, 
                1873046591, 1152974889, 1614932933, 1014132710, 1935895948, 
                1656284361, 1118023985, 2060935243, 1273805198, 1319657837, 
                541034449, 56009732, 954778937, 439645571, 525217481, 
                762429848, 64865080, 1261799192, 359623473, 2083344164, 
                807737224, 1566282239, 752634226, 96686409, 1602080858, 
                1072522315, 1136850812, 251328495, 2090919322, 801291705, 
                1352334778, 1816482265, 1954266595, 819784063, 683131328, 
                1742678895, 328584776, 1801155313, 1656130490, 1602389975, 
                973329502, 49681292, 1658399707, 1928108439, 489326863, 
                36133540, 543054639, 554191944, 1297932733, 902678112, 
                490052460, 2105669957, 321476703, 1242686687, 54872718, 
                1923557561, 167725354, 1191723530, 27402409, 111161028, 
                1993015236, 1379737187, 1927643294, 1799798183, 52037602, 
                463290974, 1394993430, 380622379, 116962639, 903640272, 
                1983012354, 1090292142, 953321564, 1493928413, 870916933, 
                1442648428, 1530061954, 1413971573, 1996840372, 680511039, 
                169166037, 339409184, 638697348, 490642741, 1582095871, 
                693570066, 266716654, 1749821226, 1885293596, 294119063, 
                1860982254, 1730825184, 1673856250, 1641141900, 1383139719, 
                1725893853, 2104432874, 630649501, 2106516232, 73911866, 
                1534289774, 1942044938, 1164204008, 340127690, 1288489703, 
                2035120941, 1782776118, 671068009, 1301608866, 1632132842, 
                1351579048, 1470774904, 1971542027, 1990276396, 1961417645, 
                1406154250, 536362814, 80650651, 1008491828, 274172763, 
                374769715, 721990435, 2004997947, 2048625965, 215648687, 
                1240654019, 1627036170, 172597914, 1871303520, 1586068754, 
                246509780, 1258109646, 1380630044, 1410713788, 1598237337, 
                521636100, 1298351081, 1233529807, 1192704109, 452476300, 
                718179002, 396799510, 1923251204, 542237381, 239592258, 
                1737185201, 1948391631, 775955073, 1817835852, 809399812, 
                1050127836, 45121919, 1531390247, 907642135, 2093747885, 
                1747038934, 812506, 1573300407, 1919636848, 1872116027, 
                1011885514, 18662980, 982742025, 245031910, 1429376768, 
                433495714, 766668010, 580244202, 1667025522, 1959372120, 
                1032720502, 237720876, 208687982, 808488058, 779958257, 
                448280240, 398189611, 580866240, 1224235313, 68541815, 
                1390266052, 126879501, 113663735, 774172651, 1034521637, 
                59927972, 373727938, 1035334143, 1633228379, 145881138, 
                759966522, 497630245, 164544119, 1742708548, 742662156, 
                1593920887, 28720614, 1509330166, 26681441, 1695746136, 
                1321218638, 1059401943, 1933467012, 1529906620, 1867890001, 
                565941621, 1978186861, 118595964, 1146807862, 1054938526, 
                187137780, 389590266, 1181818028, 300801515, 1163762918, 
                68856017, 360729487, 1537490856, 1104190160, 1993957866, 
                1683371994, 1864156683, 344104464, 1847916113, 1459381583, 
                1086766620, 1294353353, 1488102197, 448613138, 1321034794, 
                1036364686, 1769831777, 232953090, 822348050, 1152254749, 
                2100843091, 1388289672, 982957962, 71955408, 387613886, 
                2037896489, 259093188, 777204152, 1072230869, 559894703, 
                1940967070, 1141086886, 920624190, 1330974278, 97793398, 
                767098408, 866862625, 1961950081, 1111202872, 567295090, 
                1273848016, 50485844, 1861648443, 614466566, 499098983, 
                1035199590, 1650831252, 121447112, 1268152680, 325695654, 
                1273701861, 1221512123, 1713985326, 109176176, 1293467531, 
                2101599212, 2147072665, 1552560719, 731319717, 1071819886, 
                2112455422, 524803139, 65423124, 885595964, 1855777418, 
                163216522, 1652694373, 575156395, 2125166604, 616413597, 
                1142451485, 1251530972, 666899442, 856616281, 1865997538, 
                1165998425, 1891815871, 1369345142, 1287445537, 1012484903, 
                1695040797, 413663750, 86513378, 1261542475, 522839926, 
                1379980910, 1215658040, 522428943, 785057981, 1946977757, 
                1594248829, 750029756, 324297248, 1659671953, 0
            };
            
            int count_of_items = 1000;
            
        
        void SetUp() override {
            
            // Add items into tree
            for (int i = 0; i < count_of_items; i++) {
                tree.InsertNode(items[i]);
            }    
        }
    };
    
    /* 
     * Tests for empty tree
     */
    
    TEST_F(EmptyTree, InsertNode_NoInsert) {
        
        Node_t *m_pRoot = tree.GetRoot();   
        ASSERT_EQ(m_pRoot, nullptr);
    }
    
    // Add one element into tree
    TEST_F(EmptyTree, InsertNode_OneElement) {
        
        // Add one item and test it
        const int key = 42;
        
        std::pair<bool, BinaryTree::Node_t *> firstNode =   
            tree.InsertNode(key);
        
        // Test if the value was correctly add
        ASSERT_TRUE(firstNode.first);
        ASSERT_NE(firstNode.second, nullptr);
        
        // Get root node
        Node_t * root_node = tree.GetRoot();
        ASSERT_NE(root_node, nullptr);
        
        // Test color && value
        EXPECT_EQ(firstNode.second->key, key);
        EXPECT_EQ(firstNode.second->pParent, nullptr);
        EXPECT_EQ(firstNode.second->color, BinaryTree::BLACK);
        
        // Test for child elements
        BinaryTree::Node_t * left = firstNode.second->pLeft;
        BinaryTree::Node_t * right = firstNode.second->pRight;
        
        ASSERT_NE(left, nullptr);
        ASSERT_NE(right, nullptr);
        
        ASSERT_NE(left->pParent, nullptr);
        ASSERT_NE(right->pParent, nullptr);
        
        EXPECT_EQ(left->pParent, firstNode.second);
        EXPECT_EQ(right->pParent, firstNode.second);
        
        EXPECT_EQ(left->color, BinaryTree::BLACK);
        EXPECT_EQ(right->color, BinaryTree::BLACK);
        
        EXPECT_EQ(left->pLeft, nullptr);
        EXPECT_EQ(left->pRight, nullptr);
        EXPECT_EQ(right->pLeft, nullptr);
        EXPECT_EQ(right->pRight, nullptr);
        
        // Test leaf nodes with one added item
        std::vector<Node_t *> leafNodes;
        
        tree.GetLeafNodes(leafNodes);
        
        for (Node_t * node : leafNodes) {
            EXPECT_EQ(node->pParent, firstNode.second);
        }
        
        // Test all nodes with one added item
        std::vector<Node_t *> allNodes;
        
        tree.GetAllNodes(allNodes);
        
        EXPECT_EQ(allNodes.size(), 3);
        
        
        // Test non leaf nodes with one added item
        std::vector<Node_t *> NonLeafNodes;
        
        tree.GetNonLeafNodes(NonLeafNodes);
        
        EXPECT_EQ(NonLeafNodes.size(), 1);
        
    }
    
    // Insert And Delete One Element
    TEST_F(EmptyTree, InsertNode_MoreWithoutRotation) {
        
        // Important constants for testing
        const int root_key = 0;
        const int size_node_values = 3;
        const int nodes_values[size_node_values] = {
            root_key, INT32_MIN, INT32_MAX
        };

        // Three nodes INT32_MIN -> 0 <-INT32_MAX
        for(int i = 0; i < size_node_values; i++) {
            std::pair<bool, BinaryTree::Node_t *> firstNode =   
            tree.InsertNode(nodes_values[i]);
            
            // Test for result values
            ASSERT_TRUE(firstNode.first);
            ASSERT_NE(firstNode.second, nullptr);
            
        }
        
        // Get root node
        Node_t * root_node = tree.GetRoot();
        ASSERT_NE(root_node, nullptr);
        
        // Test root node
        ASSERT_EQ(root_node->key, root_key);
        EXPECT_EQ(root_node->color, BinaryTree::BLACK);
        EXPECT_EQ(root_node->pParent, nullptr);
        
        // Test child nodes
        Node_t * root_left_node = root_node->pLeft;
        Node_t * root_right_node = root_node->pRight;
        
        EXPECT_EQ(root_left_node->pParent, root_node);
        EXPECT_EQ(root_right_node->pParent, root_node);
        
        ASSERT_NE(root_left_node, nullptr);
        ASSERT_NE(root_right_node, nullptr);
        
        EXPECT_EQ(root_left_node->key, INT32_MIN);
        EXPECT_EQ(root_right_node->key, INT32_MAX);
        
        EXPECT_EQ(root_left_node->color, BinaryTree::RED);
        EXPECT_EQ(root_right_node->color, BinaryTree::RED);
        
        // test child[child nodes]
        EXPECT_EQ(root_left_node->pLeft->color, BinaryTree::BLACK);
        EXPECT_EQ(root_left_node->pRight->color, BinaryTree::BLACK);
        EXPECT_EQ(root_right_node->pLeft->color, BinaryTree::BLACK);
        EXPECT_EQ(root_right_node->pRight->color, BinaryTree::BLACK);
        
        // Test count of nodes
        std::vector<Node_t *> allNodes;
        tree.GetAllNodes(allNodes);
        EXPECT_EQ(allNodes.size(), 7);
        
        std::vector<Node_t *> NonLeafNodes;
        tree.GetNonLeafNodes(NonLeafNodes);
        EXPECT_EQ(NonLeafNodes.size(), 3); 
        
        std::vector<Node_t *> LeafNodes;
        tree.GetLeafNodes(LeafNodes);
        EXPECT_EQ(LeafNodes.size(), 4); 
        
        for (Node_t  * node : LeafNodes) {
            
            EXPECT_EQ(node->pParent->color, BinaryTree::RED);
            EXPECT_EQ(node->pParent->pParent, root_node);
            
        }
        
    }
    
    // Insert And Delete One Element
    TEST_F(EmptyTree, InsertNode_MoreWithRotation) {
        
        // Important constants for testing
        const double root_key = 2.0;
        const int size_node_values = 6;
        const double nodes_values[size_node_values] = {
            1.0, 2.0, 40.0, 50.0, 6.0, 7.0
        };
        
        for(int i = 0; i < size_node_values; i++) {
            std::pair<bool, BinaryTree::Node_t *> firstNode =   
            tree.InsertNode(nodes_values[i]);
            
            // Test for result values
            ASSERT_TRUE(firstNode.first);
            ASSERT_NE(firstNode.second, nullptr);
            
        }      
        
        // Get root node
        Node_t * root_node = tree.GetRoot();
        ASSERT_NE(root_node, nullptr);
        
        // Test root node
        ASSERT_EQ(root_node->key, root_key);
        EXPECT_EQ(root_node->color, BinaryTree::BLACK);
        EXPECT_EQ(root_node->pParent, nullptr);
        
        // Test child nodes
        Node_t * root_left_node = root_node->pLeft;
        Node_t * root_right_node = root_node->pRight;
        
        ASSERT_NE(root_left_node, nullptr);
        ASSERT_NE(root_right_node, nullptr);
        
        EXPECT_EQ(root_left_node->color, BinaryTree::BLACK);
        EXPECT_EQ(root_left_node->key, 1);
        EXPECT_EQ(root_right_node->color, BinaryTree::RED);
        EXPECT_EQ(root_right_node->key, 40);
        
        EXPECT_EQ(root_left_node->pLeft->color, BinaryTree::BLACK);
        EXPECT_EQ(root_left_node->pRight->color, BinaryTree::BLACK);
        
        EXPECT_EQ(root_left_node->pLeft->pRight, nullptr);
        EXPECT_EQ(root_left_node->pLeft->pLeft, nullptr);
        EXPECT_EQ(root_left_node->pRight->pRight, nullptr);
        EXPECT_EQ(root_left_node->pRight->pLeft, nullptr);
        
        ASSERT_EQ(root_right_node->pLeft->color, BinaryTree::BLACK);
        ASSERT_EQ(root_right_node->pLeft->key, 6);
        ASSERT_EQ(root_right_node->pRight->color, BinaryTree::BLACK);
        ASSERT_EQ(root_right_node->pRight->key, 50);
        
        EXPECT_EQ(root_right_node->pRight->pRight->color, BinaryTree::BLACK);
        EXPECT_EQ(root_right_node->pRight->pLeft->color, BinaryTree::BLACK);
        
        EXPECT_EQ(root_right_node->pRight->pRight->pLeft, nullptr);
        EXPECT_EQ(root_right_node->pRight->pRight->pRight, nullptr);
        EXPECT_EQ(root_right_node->pRight->pLeft->pLeft, nullptr);
        EXPECT_EQ(root_right_node->pRight->pLeft->pRight, nullptr);
        
        EXPECT_EQ(root_right_node->pLeft->pLeft->color, BinaryTree::BLACK);
        
        EXPECT_EQ(root_right_node->pLeft->pLeft->pRight, nullptr);
        EXPECT_EQ(root_right_node->pLeft->pLeft->pLeft, nullptr);
        
        EXPECT_EQ(root_right_node->pLeft->pRight->color, BinaryTree::RED);
        EXPECT_EQ(root_right_node->pLeft->pRight->key, 7);
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pRight->color, 
                BinaryTree::BLACK
                );
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pLeft->color, 
                BinaryTree::BLACK
                );
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pRight->pRight, 
                nullptr
                );
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pRight->pLeft, 
                nullptr
                );
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pLeft->pRight, 
                nullptr
                );
        
        EXPECT_EQ(
                root_right_node->pLeft->pRight->pLeft->pLeft, 
                nullptr
                );
        
    }
    
     // Add one element into tree
    TEST_F(EmptyTree, InsertNode_InserAndDelete) {
        
        // Add one item and test it
        const int key = 42;
        
        std::pair<bool, BinaryTree::Node_t *> firstNode =   
            tree.InsertNode(key);
        
        ASSERT_TRUE(tree.DeleteNode(key));
        
        Node_t *m_pRoot = tree.GetRoot();   
        ASSERT_EQ(m_pRoot, nullptr);
        
    }
    
    TEST_F(EmptyTree, DeleteNode) {
        
        const int count_of_numbers = 10;
        int numbers[count_of_numbers] = {
            INT32_MIN, 6767, 0, 67, 1, 8, 6, 56, 56, INT32_MAX
        };
        
        for (int i = 0; i < count_of_numbers; i++) {
           ASSERT_FALSE(tree.DeleteNode(numbers[i]));
        }
        
    }
    
    TEST_F(EmptyTree, FindNode) {
        
        const int count_of_numbers = 10;
        int numbers[count_of_numbers] = {
            INT32_MIN, 6767, 0, 67, 1, 8, 6, 56, 56, INT32_MAX
        };
        
        for (int i = 0; i < count_of_numbers; i++) {
           ASSERT_EQ(tree.FindNode(numbers[i]), nullptr);
        }
        
    }
    
    // Tests for NonEmptyTree
    TEST_F(NonEmptyTree, InsertNode) {
        
        const int firstItem = 42;
        
        std::pair<bool, BinaryTree::Node_t *> firstNode =   
            tree.InsertNode(firstItem);
        
        // Test if the value was correctly add
        ASSERT_TRUE(firstNode.first);
        ASSERT_TRUE(firstNode.second != NULL);
        
        // Test value
        EXPECT_EQ(firstNode.second->key, firstItem);
        EXPECT_EQ(firstNode.second->color, BinaryTree::RED);
        
        // Try to add existing value
        
        std::pair<bool, BinaryTree::Node_t *> firstNodeRe =   
            tree.InsertNode(firstItem);
        ASSERT_FALSE(firstNodeRe.first);
        
    }
    
    TEST_F(NonEmptyTree, DeleteNode) {
        
        const int fail_items[6] = {
            INT16_MAX, INT32_MAX, -7789, 6776, 6767897, 7667
        };
        
        const int count_of_fail_items = 6;
        
        for(int i = 0; i < count_of_fail_items; i++) {
            EXPECT_FALSE(tree.DeleteNode(fail_items[i]));
        }
        
        
        const int items[6] = {1, 56, 23, 89, 46, 78}; 
            
        const int count_of_items = 6;
        
        for(int i = 0; i < count_of_items; i++) {
            EXPECT_TRUE(tree.DeleteNode(items[i]));
        }
        
        for(int i = 0; i < count_of_items; i++) {
            EXPECT_FALSE(tree.DeleteNode(items[i]));
        }
        
    }
    
    TEST_F(NonEmptyTree, FindDone) {
        
        const int fail_items[6] = {
            INT16_MAX, INT32_MAX, -7789, 6776, 6767897, 7667
        };
        
        const int count_of_fail_items = 6;
        
        for(int i = 0; i < count_of_fail_items; i++) {
            EXPECT_EQ(tree.FindNode(fail_items[i]), nullptr);
        }
        
        
        const int items[6] = {1, 56, 23, 89, 46, 78}; 
            
        const int count_of_items = 6;
        
        for(int i = 0; i < count_of_items; i++) {
            EXPECT_NE(tree.FindNode(items[i]), nullptr);
        }
        
    }
    
    // Tests for Axioms
    TEST_F(TreeAxioms, Axiom1) {
        
        std::vector<Node_t *> LeafNodes;
        tree.GetLeafNodes(LeafNodes);
        
        for (Node_t  * node : LeafNodes) {
            EXPECT_EQ(node->color, BinaryTree::BLACK);
        }
        
    }
    
    TEST_F(TreeAxioms, Axiom2) {
        
        std::vector<Node_t *> NonLeafNodes;
        tree.GetNonLeafNodes(NonLeafNodes);
        
        for (Node_t * node : NonLeafNodes) {
            
            if(node->color == BinaryTree::RED) {
                EXPECT_EQ(node->pLeft->color, BinaryTree::BLACK);
                EXPECT_EQ(node->pRight->color, BinaryTree::BLACK);
            }
            
        }
        
    }
    
    TEST_F(TreeAxioms, Axiom3) {
        
        std::vector<Node_t *> LeafNodes;
        tree.GetLeafNodes(LeafNodes);
        
        int way_lengts = 0;
        bool first_way = true;
        
        for (Node_t  * node : LeafNodes) {
            
            if(first_way) {
                
                while(node != nullptr) {
                    if(node->color == BinaryTree::BLACK) {
                        way_lengts++;
                    }
                    node = node->pParent;
                } 
                
            }
            else {
                int actual_way = 0;
                
                while(node != nullptr) {
                    if(node->color == BinaryTree::BLACK) {
                        actual_way++;
                    }
                    node = node->pParent;
                }
                
                ASSERT_EQ(actual_way, way_lengts);
            }
            
            first_way = false;
        }
        
    }
        
    
}
