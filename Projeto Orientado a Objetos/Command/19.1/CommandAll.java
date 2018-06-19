import java.util.HashMap;
import java.util.Set;

public class CommandAll implements Command
{
	public void all(HashMap<Long,String> map)
	{
		Set<Long> idList = map.keySet();
		for(Long id : idList)
		{
			System.out.println(map.get(id));
		}
	}

	@Override
	public void execute(HashMap<Long, String> map, Long id, String nome) {
		all(map);
	}

	
}