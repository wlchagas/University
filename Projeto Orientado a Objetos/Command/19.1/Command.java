import java.util.HashMap;

public interface Command
{
	public void execute(HashMap<Long,String> map, Long id, String nome);
}