import java.util.HashMap;
import java.util.Set;

public class CommandDelete implements Command
{
	
	public void delete(Long id, HashMap<Long,String> map)
	{
		map.remove(id);
	}

	@Override
	public void execute(HashMap<Long, String> map, Long id, String nome) {
		delete(id, map);
	}
	
}