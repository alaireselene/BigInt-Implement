#include "bigint.hpp"
#include <gtest/gtest.h>

TEST(Add, Zero) {
  BigInt a = randomize(1000);
  BigInt b(0);
  EXPECT_EQ(a + b, a);
}

TEST(Add, SmallPos) {
  BigInt a("4710563139");
  BigInt b("4574205686");
  EXPECT_EQ((a + b).toString(), "9284768825");
}

TEST(Add, SmallNeg) {
  BigInt a("-2183253674");
  BigInt b("-6144869561");
  BigInt sum = a + b;
  EXPECT_EQ(sum.toString(), "-8328123235");
}

TEST(Add, SmallPosNeg) {
  BigInt a("-2464220006");
  BigInt b("4690936914");
  BigInt sum = a + b;
  EXPECT_EQ(sum.toString(), "2226716908");
}

TEST(Add, MedPos) {
  BigInt a("19099983446341341855527159541893906104847511927640");
  BigInt b("98063748596240140787111919550786557475297845682498");
  BigInt sum = a + b;
  EXPECT_EQ(sum.toString(),
            "117163732042581482642639079092680463580145357610138");
}

TEST(Add, MedNeg) {
  BigInt a("-64439323504705445441430280216830091066140199887377");
  BigInt b("-38343618526002969434892157587017158229423031885395");
  BigInt sum = a + b;
  EXPECT_EQ(sum.toString(),
            "-102782942030708414876322437803847249295563231772772");
}

TEST(Add, MedPosNeg) {
  BigInt a("57514582578764669035408117045996526595765134610763");
  BigInt b("-82441073467097648317529446244604436147739204635969");
  BigInt sum = a + b;
  EXPECT_EQ(sum.toString(),
            "-24926490888332979282121329198607909551974070025206");
}

TEST(Add, LargePos) {
  BigInt a(
      "-86385904913145420329137035158279435121854926779267731389037000083187851"
      "412958113404332308433645659882997311204799112760121614177347672803714945"
      "571482129113537015423240987980537817016319295745963762310659637506700056"
      "567412504283907117813369323449992635863232416385051134358443280438261912"
      "349567133589722469064094309755899889216446726634422985243881118590812483"
      "470344783593610944878835300834380913823648803687786103089061700843051756"
      "210253514847264625234247401708347709125668001238817447670157906168549408"
      "975018310876558518620548033602593253779713441724763602056104802448587944"
      "299256380255215789280344572002803888814337452248471418177726980922006195"
      "222862423457318286931593229625723868782380008766279938776569233228788726"
      "898334950573756831335427043099850573048143818357113224445927676421819493"
      "525131062653354494065787891790970836468779718244558977339250261718939431"
      "054951621903690328482429718105141994706564707248672844960063307842510399"
      "75195946406558339231334313847590142628070070576373845540299335845");
  BigInt b(
      "326603305735386449520131784989060338409248768446752984966053012494140631"
      "457051911775476759440883707931868902573126385985815268572473751576782541"
      "841914571935104278362745487571660125828868255097458473893461838805164595"
      "927145604618450776302187420054025918429740623988288968768063533062443070"
      "511522319425616504198618940046318351878629485127185058817393921544393973"
      "936989573438400290234603680737292237055250516058715862882088143967471447"
      "967509816292404207123732069158562631242382276477718389457483341109273610"
      "711323571266841865933467395616808669176278662237577936949011911746459862"
      "198995641506204939470906205140938158043475445142212894200750652872350681"
      "817155587777294374140067478008359094886709836314684617649837640268849125"
      "588520227772752267225720911335250738374583512816019524688132660588274541"
      "935536387023309203223282876829319881367543859227800504345138961665925178"
      "622989409783198837961495589943009556032433616391710908648075952297951700"
      "074160089500317766654481510215334701868277121258326001403978107");
  BigInt sum = a + b;
  EXPECT_EQ(
      sum.toString(),
      "-83119871855791555833935717308388831737762439094800201539376469958246445"
      "098387594286577540839236822803678622179067848900263461491622935287947120"
      "153062983394185972639613533104821215758030613194989177571725019118648410"
      "608141048237722610050347449249452376678935010145168244670762645107637481"
      "644451910395466304022108120355436705697660431783151134655707179375368543"
      "730974887859226941976489264027007991453096298527198944460240819403377041"
      "730578416684340583163010081016762082813244178474040263775583072757456672"
      "867905075163890099961213359646425167087950655102387822686614683331123345"
      "677266423840153739885635509951394507233902697797049289235719474393282688"
      "404690867579545343190192554845640277833512910403133092600070856826100235"
      "642449748296029308663169833986498065664397983228953029199046349815936748"
      "105775698783121402033555063022677637655104279652280972295798872102280179"
      "268721727805858340102814762205711899146240371084755735873582548319530882"
      "75121786317058021464679832337374807926201793455115519538895357738");
}